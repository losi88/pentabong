
#pragma once

#include "ari/buffer.h"
#include "ari/socket.h"
#include "asio/ip/tcp.hpp"

namespace ari {
class Session;
}  // namespace ari

namespace ari {
class TcpSocket : public Socket {
public:
    TcpSocket(asio::ip::tcp::socket socket);
    TcpSocket(const TcpSocket&) = delete;
    TcpSocket(TcpSocket&&) = delete;
    virtual ~TcpSocket();

public:
    virtual void AsyncRead(std::shared_ptr<Session> session) override final;
    virtual void AsyncWrite(
        std::shared_ptr<Session> session,
        std::unique_ptr<const Buffer> buffer) override final;

private:
    asio::ip::tcp::socket _socket;
    Buffer _readBuffer;
};
}  // namespace ari
