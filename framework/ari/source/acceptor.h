
#pragma once

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
class NetworkHandler;
} // namespace ari

namespace ari {
class Acceptor {
public:
    Acceptor(asio::io_context& ioContext,
             const asio::ip::tcp::endpoint& endPoint,
             const std::shared_ptr<const NetworkHandler>& networkHandler);
    Acceptor(const Acceptor&) = delete;
    virtual ~Acceptor();

private:
    void accept();

private:
    asio::ip::tcp::acceptor _acceptor;
    const std::shared_ptr<const NetworkHandler> _networkHandler;
};
}  // namespace ari
