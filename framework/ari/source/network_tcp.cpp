
#include "network_tcp.h"

#include "acceptor.h"
#include "asio/io_context.hpp"
#include "asio/ip/tcp.hpp"

namespace ari {
Network_TCP::Network_TCP(const IP ip, const int port, const int acceptCount)
    : _ip(ip), _port(port), _acceptCount(acceptCount) {}

Network_TCP::~Network_TCP() {}

bool Network_TCP::Start() {
    asio::io_context ioContext;
    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), _port);

    for (auto i = 0; i < _acceptCount; ++i) {
        _acceptorList.push_back(
            std::make_unique<Acceptor>(ioContext, endpoint));
    }

    ioContext.run();
    return true;
}
}  // namespace ari
