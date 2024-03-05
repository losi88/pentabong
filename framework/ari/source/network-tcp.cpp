
#include "network-tcp.h"

#include "acceptor.h"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
Network_TCP::Network_TCP(const IP ip, const int port) : _ip(ip), _port(port) {}

Network_TCP::~Network_TCP() {}

bool Network_TCP::Start() {
    switch (_ip) {
        case IP::V4: {
            asio::io_context ioContext;
            asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), _port);

            auto acceptor = std::make_unique<Acceptor>(ioContext, endpoint);
            ioContext.run();

            return true;
        }
        case IP::V6: {
            break;
        }
        default:
            break;
    }

    return false;
}
}  // namespace ari
