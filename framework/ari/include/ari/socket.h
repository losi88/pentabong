
#pragma once

#include "ari/ari.h"

namespace ari {
class Socket {
public:
    virtual ~Socket() {}

public:
    virtual void Read() = 0;
    virtual void Write() = 0;
};
}  // namespace ari
