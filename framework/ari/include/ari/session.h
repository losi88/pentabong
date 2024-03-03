
#pragma once

#include "ari/ari.h"

namespace ari {
class Socket;
}

namespace ari {
class ARI_API Session : public std::enable_shared_from_this<Session> {
public:
    static std::shared_ptr<Session> Make(const int64_t id);

public:
    Session(const int64_t id);
    Session(const Session&) = delete;
    virtual ~Session();

private:
    const int64_t _id;
    std::unique_ptr<Socket> _socket;
};
}  // namespace ari
