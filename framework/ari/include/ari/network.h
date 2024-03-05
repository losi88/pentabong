
#pragma once

#include "ari/ari.h"

namespace ari {
enum class ARI_API IP { None, V4, V6 };
class ARI_API Network {
public:
    static std::unique_ptr<Network> TCP(const IP ip, const int port);

public:
    virtual ~Network() {}

public:
    virtual bool Start() = 0;
};
}  // namespace ari