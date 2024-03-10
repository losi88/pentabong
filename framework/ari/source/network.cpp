
#include "ari/network.h"

#include "ari/session.h"
#include "ari/sessionmanager.h"
#include "ari/socket.h"
#include "network-tcp.h"

namespace ari {
std::unique_ptr<Network> Network::TCP(
    const IP ip, const int port,
    const std::shared_ptr<const NetworkHandler>& networkHandler) {
    return std::make_unique<Network_TCP>(ip, port, networkHandler);
}
}  // namespace ari