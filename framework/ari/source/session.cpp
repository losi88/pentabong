
#include "ari/session.h"

#include "ari/buffer.h"
#include "ari/socket.h"
#include "network-tcp.h"

namespace ari {
std::unique_ptr<Session> Session::Create(std::unique_ptr<Socket> socket,
                                         const Network_TCP& network) {
    static std::atomic_int64_t _idGenerator = 0;
    int64_t id = ++_idGenerator;
    return std::make_unique<Session>(id, std::move(socket), network);
}

Session::Session(const int64_t id, std::unique_ptr<Socket> socket,
                 const Network_TCP& network)
    : _id(id), _socket(std::move(socket)), _network(network) {
}

Session::~Session() {
    // info: delete session
}

std::shared_ptr<Session> Session::SharedPtr() {
    return shared_from_this();
}

std::shared_ptr<const Session> Session::SharedPtr() const {
    return shared_from_this();
}

bool Session::Write(std::unique_ptr<const Buffer> buffer) {
    if (nullptr == _socket) {
        // err: socket is nullptr
        return false;
    }

    _socket->AsyncWrite(SharedPtr(), std::move(buffer));
    return true;
}

void Session::OnRead(const size_t size, const char* data) const {
    _network.OnReceived(*this, size, data);
}

void Session::OnClose() const {
    _network.OnClosed(*this);
}

bool Session::Start() {
    _socket->AsyncRead(SharedPtr());
    return true;
}
}  // namespace ari
