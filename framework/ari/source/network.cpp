
#include "ari/network.h"

#include "network_tcp.h"

namespace ari {
std::unique_ptr<Network> Network::Make(const Protocol protocol, const IP ip,
                                       const int port) {
    return std::make_unique<Network_TCP>(ip, port);
}
}  // namespace ari