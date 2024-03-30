
#pragma once

#include "ari/ari.h"

namespace ari {
class Buffer;
class Socket;
class Network_TCP;
}  // namespace ari

namespace ari {
class ARI_API Session : public std::enable_shared_from_this<Session> {
public:
    static std::unique_ptr<Session> Create(std::unique_ptr<Socket> socket,
                                           const Network_TCP& network);

public:
    Session(const int64_t id, std::unique_ptr<Socket> socket,
            const Network_TCP& network);
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
    bool Write(std::unique_ptr<const Buffer> buffer);

private:
    void OnRead(const size_t size, const char* data) const;
    void OnClose() const;

    friend class TcpSocket;

private:
    bool Start();

    friend class Acceptor;
    friend class Network_TCP;

private:
    const int64_t _id;
    std::unique_ptr<Socket> _socket;
    const Network_TCP& _network;
};
}  // namespace ari
