
#include "tcpsocket.h"

#include <iostream>

#include "ari/session.h"
#include "asio.hpp"

namespace ari {
TcpSocket::TcpSocket(asio::ip::tcp::socket socket)
    : _socket(std::move(socket)), _readBuffer(Buffer::_MIN_CAPACITY) {
}

TcpSocket::~TcpSocket() {
}

void TcpSocket::AsyncRead(std::shared_ptr<Session> session) {
    char* raw = const_cast<char*>(_readBuffer.Raw());
    asio::async_read(_socket, asio::buffer(raw, _readBuffer.Capacity()),
                     asio::transfer_at_least(4),
                     [this, session](std::error_code ec, size_t length) {
                         if (!ec) {
                             session->OnRead(length, _readBuffer.Raw());
                             _readBuffer.Reset();
                             AsyncRead(session);
                         } else {
                             session->OnClose();
                         }
                     });
}

void TcpSocket::AsyncWrite(std::shared_ptr<Session> session,
                           std::unique_ptr<const Buffer> buffer) {
    asio::async_write(_socket, asio::buffer(buffer->Raw(), buffer->Size()),
                      [this, session](std::error_code ec, size_t length) {
                          if (!ec) {
                          } else {
                              // err:
                          }
                      });
}
}  // namespace ari
