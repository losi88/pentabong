
#pragma once

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
class Acceptor {
public:
    Acceptor(asio::io_context& ioContext,
             const asio::ip::tcp::endpoint& endPoint);
    Acceptor(const Acceptor&) = delete;
    virtual ~Acceptor();

private:
    void accept();

private:
    asio::ip::tcp::acceptor _acceptor;
};
}  // namespace ari
