
#include "ari/network.h"

#include "network_tcp.h"

namespace ari {
std::unique_ptr<Network> Network::TCP(const IP ip, const int port,
                                      const int acceptCount) {
    return std::make_unique<Network_TCP>(ip, port, acceptCount);
}
}  // namespace ari