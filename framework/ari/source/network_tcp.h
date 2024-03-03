
#pragma once

#include <vector>

#include "ari/network.h"

namespace ari {
class Acceptor;
}

namespace ari {
class Network_TCP : public Network {
public:
    Network_TCP(const IP ip, const int port, const int acceptCount);
    Network_TCP(const Network_TCP&) = delete;
    virtual ~Network_TCP();

public:
    virtual bool Start() override final;

private:
    typedef std::vector<std::unique_ptr<Acceptor>> AcceptorList;

    const IP _ip;
    const int _port;
    const int _acceptCount;
    AcceptorList _acceptorList;
};
}  // namespace ari
