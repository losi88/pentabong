
#include "acceptor.h"

#include "network-tcp.h"
#include "tcpsocket.h"

namespace ari {
Acceptor::Acceptor(asio::io_context& ioContext,
                   const asio::ip::tcp::endpoint& endPoint,
                   const Network_TCP& network)
    : _acceptor(ioContext, endPoint), _network(network) {
    accept();
}

Acceptor::~Acceptor() {}

void Acceptor::accept() {
    _acceptor.async_accept(
        [this](std::error_code errorCode, asio::ip::tcp::socket socket) {
            if (!errorCode) {
                auto tcpSocket = std::make_unique<TcpSocket>(std::move(socket));
                _network.OnAccepted(std::move(tcpSocket));
            }

            accept();
        });
}

}  // namespace ari
