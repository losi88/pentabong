
#pragma once

#include <vector>

#include "ari/network.h"

namespace ari {
class Acceptor;
}

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

private:
    typedef std::vector<std::unique_ptr<Acceptor>> AcceptorList;

    const IP _ip;
    const int _port;
    const std::shared_ptr<const NetworkHandler> _networkHandler;
};
}  // namespace ari
