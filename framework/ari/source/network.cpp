
#include "ari/network.h"

#include "network-tcp.h"

namespace ari {
std::unique_ptr<Network> Network::TCP(const IP ip, const int port) {
    return std::make_unique<Network_TCP>(ip, port);
}
}  // namespace ari