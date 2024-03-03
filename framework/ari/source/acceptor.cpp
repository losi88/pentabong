
#include "acceptor.h"

#include <iostream>

namespace ari {
Acceptor::Acceptor(asio::io_context& ioContext,
                   const asio::ip::tcp::endpoint& endPoint)
    : _acceptor(ioContext, endPoint) {
    accept();
}

Acceptor::~Acceptor() {}

void Acceptor::accept() {
    _acceptor.async_accept(
        [this](std::error_code errorCode, asio::ip::tcp::socket socket) {
            if (!errorCode) {
                std::cout << "accept" << std::endl;
            }

            accept();
        });
}

}  // namespace ari
