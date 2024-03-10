
#pragma once

#include "ari/ari.h"

namespace ari {
class Socket;
} // namespace ari

namespace ari {
class ARI_API Session : public std::enable_shared_from_this<Session> {
public:
    static std::shared_ptr<Session> Make(const int64_t id, std::unique_ptr<Socket> socket);

public:
    Session(const int64_t id, std::unique_ptr<Socket> socket);
    Session(const Session&) = delete;
    Session(Session&&) = delete;
    virtual ~Session();

public:
    int64_t ID() const { return _id; };

public:
    bool Start();

private:
    void doRead();
    void doWrite();

private:
    const int64_t _id;
    std::unique_ptr<Socket> _socket;
};
}  // namespace ari
