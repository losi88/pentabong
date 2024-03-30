
#pragma once

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
class Network_TCP;
class TcpSocket;
}  // namespace ari

namespace ari {
class Connector {
public:
    Connector(asio::io_context& ioContext,
              const asio::ip::tcp::resolver::results_type& endpoints,
              const Network_TCP& network);
    Connector(const Connector&) = delete;
    Connector(Connector&&) = delete;
    virtual ~Connector();

private:
    void connect(const asio::ip::tcp::resolver::results_type& endpoints);

private:
    std::unique_ptr<TcpSocket> _socket; // do not use, after connect
    const Network_TCP& _network;
};
}  // namespace ari
