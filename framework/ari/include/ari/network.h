
#pragma once

#include "ari/ari.h"

namespace ari {
enum class ARI_API IP { V4, V6 };
class ARI_API Network {
public:
    static std::unique_ptr<Network> TCP(const IP ip, const int port,
                                        const int acceptCount);

public:
    virtual ~Network() {}

public:
    virtual bool Start() = 0;
};
}  // namespace ari