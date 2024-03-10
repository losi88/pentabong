
#include "ari/session.h"

#include "ari/socket.h"

namespace ari {
std::shared_ptr<Session> Session::Make(const int64_t id,
                                       std::unique_ptr<Socket> socket) {
    return std::make_shared<Session>(id, std::move(socket));
}

Session::Session(const int64_t id, std::unique_ptr<Socket> socket)
    : _id(id), _socket(std::move(socket)) {}

Session::~Session() {}

bool Session::Start() {
    doRead();
    return true;
}

void Session::doRead() {
    auto self(shared_from_this());
    _socket->Read();
}

void Session::doWrite() {}
}  // namespace ari
