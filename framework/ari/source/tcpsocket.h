
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
    TcpSocket(asio::ip::tcp::socket socket, const Session& session);
    TcpSocket(const TcpSocket&) = delete;
    TcpSocket(TcpSocket&&) = delete;
    virtual ~TcpSocket();

public:
    virtual void Read() override final;
    virtual void Write() override final;

private:
    asio::ip::tcp::socket _socket;
    Buffer _readBuffer;
    const Session& _session;  // have same life-cycle
};
}  // namespace ari
