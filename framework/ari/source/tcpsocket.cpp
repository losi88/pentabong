
#include "tcpsocket.h"

#include <iostream>

#include "ari/session.h"
#include "asio.hpp"

namespace ari {
TcpSocket::TcpSocket(asio::ip::tcp::socket socket, const Session& session)
    : _socket(std::move(socket)),
      _readBuffer(Buffer::_MIN_CAPACITY),
      _session(session) {
}

TcpSocket::~TcpSocket() {
}

void TcpSocket::Read() {
    char* raw = const_cast<char*>(_readBuffer.Raw());
    asio::async_read(
        _socket, asio::buffer(raw, _readBuffer.Capacity()),
        asio::transfer_at_least(4), [this](std::error_code ec, size_t length) {
            if (!ec) {
                _session.OnRead(length, _readBuffer.Raw());
                _readBuffer.Reset();
                Read();
            } else {
                _session.OnClose();
            }
        });
}

void TcpSocket::Write() {
}
}  // namespace ari
