
#include "network-tcp.h"

#include "acceptor.h"
#include "ari/session.h"
#include "ari/sessionmanager.h"
#include "ari/socket.h"
#include "asio.hpp"
#include "connector.h"

namespace ari {
Network_TCP::Network_TCP(
    const std::shared_ptr<const NetworkHandler>& networkHandler)
    : Network(),
      _networkHandler(networkHandler),
      _sessionManager(std::make_unique<SessionManager>()) {
}

Network_TCP::~Network_TCP() {
}

bool Network_TCP::OpenPort(const IP ip, const int port) {
    switch (ip) {
        case IP::V4: {
            asio::io_context ioContext;
            asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);

            auto acceptor =
                std::make_unique<Acceptor>(ioContext, endpoint, *this);
            ioContext.run();

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
    // @TODO
    return false;
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
}  // namespace ari
