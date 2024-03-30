
#pragma once

#include "ari/ari.h"

namespace ari {
class Buffer;
class Session;
}  // namespace ari

namespace ari {
class Socket {
public:
    virtual ~Socket() {
    }

public:
    virtual void AsyncRead(std::shared_ptr<Session> session) = 0;
    virtual void AsyncWrite(std::shared_ptr<Session> session,
                            std::unique_ptr<const Buffer> buffer) = 0;
};
}  // namespace ari
