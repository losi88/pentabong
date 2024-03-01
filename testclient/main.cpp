
#include <iostream>
#include <thread>

#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/connect.hpp"

int main(int argc, int** argv)
{ 
    asio::io_context ioContext;

    asio::ip::tcp::resolver resolver(ioContext);
    auto endpoints = resolver.resolve("localhost", "8080");
    
    auto socket = asio::ip::tcp::socket(ioContext);

    asio::async_connect(socket,endpoints,
        [](std::error_code ec, asio::ip::tcp::endpoint)
        {
            if (!ec)
            {
                std::cout << "connect" << std::endl;
            }
        });

    ioContext.run();

    return 0;
}
