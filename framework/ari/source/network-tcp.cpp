
#include "network-tcp.h"

#include "acceptor.h"
#include "ari/session.h"
#include "ari/sessionmanager.h"
#include "ari/socket.h"
#include "connector.h"

namespace ari {
Network_TCP::Network_TCP(
    const std::shared_ptr<const NetworkHandler>& networkHandler)
    : Network(),
      _networkHandler(networkHandler),
      _sessionManager(std::make_unique<SessionManager>()),
      _ioContext(),
      _ioContextThread(nullptr),
      _acceptorMapMtx(),
      _acceptorMap() {
}

Network_TCP::~Network_TCP() {
    _acceptorMap.clear();

    if (_ioContextThread) {
        _ioContext.stop();
        _ioContextThread->join();
        delete _ioContextThread;
    }
}

bool Network_TCP::OpenPort(const IP ip, const int port) {
    if (!_ioContextThread) {
        _ioContextThread = new std::thread([this]() {
            asio::executor_work_guard<asio::io_context::executor_type>
                executorWorkGuard(_ioContext.get_executor());
            _ioContext.run();
        });
    }

    switch (ip) {
        case IP::V4: {
            asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);

            auto acceptor =
                std::make_shared<Acceptor>(_ioContext, endpoint, *this);
            insertAcceptor({ip, port}, acceptor);

            return true;
        }
        case IP::V6: {
            break;
        }
        default:
            break;
    }

    return false;
}

bool Network_TCP::ClosePort(const IP ip, const int port) {
    return eraseAcceptor({ip, port});
}

bool Network_TCP::Connect(const char* host, const char* port) {
    asio::io_context ioContext;
    asio::ip::tcp::resolver resolver(ioContext);
    auto endpoints = resolver.resolve(host, port);

    auto connector = std::make_unique<Connector>(ioContext, endpoints, *this);
    ioContext.run();

    return true;
}

void Network_TCP::OnAccepted(std::unique_ptr<Session> session) const {
    auto inserted = _sessionManager->InsertSession(std::move(session));
    if (nullptr == inserted) {
        // failed to insert session
        return;
    }

    _networkHandler->onAccepted(inserted);
    inserted->Start();
}

void Network_TCP::OnReceived(const Session& session, const size_t size,
                             const char* data) const {
    _networkHandler->onReceived(session.SharedPtr(), size, data);
}

void Network_TCP::OnClosed(const Session& session) const {
    _networkHandler->onClosed(session.SharedPtr());
    _sessionManager->EraseSession(session.ID());
}

void Network_TCP::OnConnected(std::unique_ptr<Session> session) const {
    auto inserted = _sessionManager->InsertSession(std::move(session));
    if (nullptr == inserted) {
        // failed to insert session
        return;
    }

    _networkHandler->onConnected(inserted);
    inserted->Start();
}

bool Network_TCP::insertAcceptor(const AcceptorKey& key,
                                 const std::shared_ptr<Acceptor>& acceptor) {
    std::unique_lock<std::mutex> lk(_acceptorMapMtx);
    
    auto it = _acceptorMap.find(key);
    if (_acceptorMap.end() != it) {
        // already exists
        return false;
    }

    _acceptorMap.insert(std::make_pair(key, acceptor));
    return true;
}

bool Network_TCP::eraseAcceptor(const AcceptorKey& key) {
    std::unique_lock<std::mutex> lk(_acceptorMapMtx);
    
    auto it = _acceptorMap.find(key);
    if (_acceptorMap.end() == it) {
        // cannot find acceptor
        return false;
    }

    _acceptorMap.erase(it);
    return true;
}

size_t Network_TCP::AcceptorKey::Hasher::operator()(
    const AcceptorKey& rhs) const {
    return std::hash<int>{}(rhs.port);
}

bool Network_TCP::AcceptorKey::EqualTo::operator()(
    const AcceptorKey& lhs, const AcceptorKey& rhs) const {
    return (lhs.ip == rhs.ip) && (lhs.port == rhs.port);
}
}  // namespace ari
