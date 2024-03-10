
#pragma once

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
class Network_TCP;
}  // namespace ari

namespace ari {
class Acceptor {
public:
    Acceptor(asio::io_context& ioContext,
             const asio::ip::tcp::endpoint& endPoint,
             const Network_TCP& network);
    Acceptor(const Acceptor&) = delete;
    virtual ~Acceptor();

private:
    void accept();

private:
    asio::ip::tcp::acceptor _acceptor;
    const Network_TCP& _network;
};
}  // namespace ari
