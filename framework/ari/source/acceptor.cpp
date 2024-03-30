
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
                auto tcpSocket = std::make_unique<TcpSocket>(std::move(socket));
                auto session = Session::Create(std::move(tcpSocket), _network);
                _network.OnAccepted(std::move(session));
            } else {
                // err: failed to accept
                return;
            }

            accept();
        });
}

}  // namespace ari
