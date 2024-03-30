
#include "connector.h"

#include "asio.hpp"
#include "tcpsocket.h"
#include "network-tcp.h"
#include "ari/session.h"

namespace ari {
Connector::Connector(asio::io_context& ioContext,
                     const asio::ip::tcp::resolver::results_type& endpoints,
                     const Network_TCP& network)
    : _network(network) {
    auto socket = asio::ip::tcp::socket(ioContext);
    _socket = std::make_unique<TcpSocket>(std::move(socket));
    connect(endpoints);
}

Connector::~Connector() {
}

void Connector::connect(
    const asio::ip::tcp::resolver::results_type& endpoints) {
    asio::async_connect(
        _socket->Socket(), endpoints,
        [this](std::error_code errorCode, asio::ip::tcp::endpoint endpoint) {
            if (!errorCode) {
                auto session = Session::Create(std::move(_socket), _network);
                _network.OnConnected(std::move(session));
            } else {
                // err: failed to connect
                return;
            }
        });
}
}  // namespace ari
