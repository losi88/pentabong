
#include "network-tcp.h"

#include "acceptor.h"
#include "ari/session.h"
#include "ari/sessionmanager.h"
#include "ari/socket.h"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
Network_TCP::Network_TCP(
    const IP ip, const int port,
    const std::shared_ptr<const NetworkHandler>& networkHandler)
    : Network(),
      _ip(ip),
      _port(port),
      _networkHandler(networkHandler),
      _sessionManager(std::make_unique<SessionManager>()) {
}

Network_TCP::~Network_TCP() {
}

bool Network_TCP::Start() {
    switch (_ip) {
        case IP::V4: {
            asio::io_context ioContext;
            asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), _port);

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

void Network_TCP::OnAccepted(Session* session) const {
    auto inserted = _sessionManager->InsertSession(session);
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
}  // namespace ari
