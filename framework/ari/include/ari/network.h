
#pragma once

#include "ari/ari.h"

namespace ari {
class Session;
}

namespace ari {
class ARI_API NetworkHandler : std::enable_shared_from_this<NetworkHandler> {
public:
    virtual void OnAccepted(std::shared_ptr<Session>& session) const = 0;
    virtual void OnReceived() const = 0;
    virtual void OnClosed() const = 0;
};

enum class ARI_API IP { None, V4, V6 };
class ARI_API Network {
public:
    static std::unique_ptr<Network> TCP(
        const IP ip, const int port,
        const std::shared_ptr<const NetworkHandler>& networkHandler);

public:
    virtual ~Network() {}

public:
    virtual bool Start() = 0;
};
}  // namespace ari