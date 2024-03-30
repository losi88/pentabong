
#pragma once

#include "ari/ari.h"

namespace ari {
class Socket;
class Network_TCP;
}  // namespace ari

namespace ari {
class ARI_API Session : public std::enable_shared_from_this<Session> {
public:
    static Session* Create(const Network_TCP& network);

public:
    Session(const int64_t id, const Network_TCP& network);
    Session(const Session&) = delete;
    Session(Session&&) = delete;
    virtual ~Session();

public:
    int64_t ID() const {
        return _id;
    };

    std::shared_ptr<Session> SharedPtr();
    std::shared_ptr<const Session> SharedPtr() const;

public:
    void OnRead(const size_t size, const char* data) const;
    void OnClose() const;

private:
    bool Initialize(std::unique_ptr<Socket> socket);
    bool Start();

    friend class Acceptor;
    friend class Network_TCP;

private:
    void doRead();
    void doWrite();

private:
    const int64_t _id;
    std::unique_ptr<Socket> _socket;
    const Network_TCP& _network;
};
}  // namespace ari
