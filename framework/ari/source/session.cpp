
#include "ari/session.h"

#include "ari/socket.h"
#include "network-tcp.h"

namespace ari {
Session* Session::Create(const Network_TCP& network) {
    static std::atomic_int64_t _idGenerator = 0;
    int64_t id = ++_idGenerator;
    return new Session(id, network);
}

Session::Session(const int64_t id, const Network_TCP& network)
    : _id(id), _socket(nullptr), _network(network) {
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

void Session::OnRead(const size_t size, const char* data) const {
    _network.OnReceived(*this, size, data);
}

void Session::OnClose() const {
    _network.OnClosed(*this);
}

bool Session::Initialize(std::unique_ptr<Socket> socket) {
    if (_socket) {
        // already initialize
        return false;
    }

    _socket = std::move(socket);
    return true;
}

bool Session::Start() {
    doRead();
    return true;
}

void Session::doRead() {
    auto self(shared_from_this());
    _socket->Read();
}

void Session::doWrite() {
}
}  // namespace ari
