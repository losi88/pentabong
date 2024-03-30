
#include "acceptor.h"

#include "ari/session.h"
#include "network-tcp.h"
#include "tcpsocket.h"

namespace ari {
Acceptor::Acceptor(asio::io_context& ioContext,
                   const asio::ip::tcp::endpoint& endPoint,
                   const Network_TCP& network)
    : _acceptor(ioContext, endPoint), _network(network) {
    accept();
}

Acceptor::~Acceptor() {
}

void Acceptor::accept() {
    _acceptor.async_accept(
        [this](std::error_code errorCode, asio::ip::tcp::socket socket) {
            if (!errorCode) {
                auto session = Session::Create(_network);
                auto tcpSocket =
                    std::make_unique<TcpSocket>(std::move(socket), *session);
                if (false == session->Initialize(std::move(tcpSocket))) {
                    // failed to initialize session
                } else {
                    _network.OnAccepted(session);
                }
            }

            accept();
        });
}

}  // namespace ari
