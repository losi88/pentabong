
#pragma once

#include <vector>

#include "ari/network.h"

namespace ari {
class SessionManager;
class Session;
}  // namespace ari

namespace ari {
class Network_TCP : public Network {
public:
    Network_TCP(const IP ip, const int port,
                const std::shared_ptr<const NetworkHandler>& networkHandler);
    Network_TCP(const Network_TCP&) = delete;
    Network_TCP(Network_TCP&&) = delete;
    virtual ~Network_TCP();

public:
    virtual bool Start() override final;

public:
    void OnAccepted(Session* session) const;
    void OnReceived(const Session& session, const size_t size,
                    const char* data) const;
    void OnClosed(const Session& session) const;

private:
    const IP _ip;
    const int _port;
    const std::shared_ptr<const NetworkHandler> _networkHandler;
    const std::unique_ptr<SessionManager> _sessionManager;
};
}  // namespace ari
