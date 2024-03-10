
#include <iostream>
#include <thread>

#include "asio.hpp"

int main(int argc, int** argv) {
    asio::io_context ioContext;

    asio::ip::tcp::resolver resolver(ioContext);
    auto endpoints = resolver.resolve("localhost", "8080");

    auto socket = asio::ip::tcp::socket(ioContext);

    asio::async_connect(socket, endpoints,
                        [](std::error_code ec, asio::ip::tcp::endpoint) {
                            if (!ec) {
                                std::cout << "connect" << std::endl;
                            }
                        });

    std::thread t([&ioContext]() { ioContext.run(); });

    const size_t _MAX_LENGTH = 128;
    char line[_MAX_LENGTH];
    while (std::cin.getline(line, _MAX_LENGTH + 1)) {
        asio::async_write(socket, asio::buffer(line, strlen(line)),
                          [](std::error_code ec, std::size_t length) {
                              if (!ec) {
                              } else {
                              }
                          });
    }

    t.join();

    return 0;
}
