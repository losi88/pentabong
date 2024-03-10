
#pragma once

#include "asio/ip/tcp.hpp"

#include "ari/buffer.h"
#include "ari/socket.h"

namespace ari {
class TcpSocket : public Socket {
public:
    TcpSocket(asio::ip::tcp::socket socket);
    TcpSocket(const TcpSocket&) = delete;
    TcpSocket(TcpSocket&&) = delete;
    virtual ~TcpSocket();\

public:
    virtual void Read() override final;
    virtual void Write() override final;

private:
    asio::ip::tcp::socket _socket;
    Buffer _readBuffer;
};
}  // namespace ari
