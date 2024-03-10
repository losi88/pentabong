
#include "tcpsocket.h"

#include <iostream>
#include "asio.hpp"

namespace ari {
TcpSocket::TcpSocket(asio::ip::tcp::socket socket)
    : _socket(std::move(socket)), _readBuffer(Buffer::_MIN_CAPACITY) {}

TcpSocket::~TcpSocket() {}

void TcpSocket::Read() {
    char* raw = const_cast<char*>(_readBuffer.Raw());
    asio::async_read(_socket, asio::buffer(raw, _readBuffer.Capacity()),
                     asio::transfer_at_least(4),
                     [this](std::error_code ec, size_t length) {
                         if (!ec) {
                             std::cout << _readBuffer.Raw() << std::endl;
                             Read();
                         } else {
                         }
                     });
}

void TcpSocket::Write() {}
}  // namespace ari
