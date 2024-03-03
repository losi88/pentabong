
#include "ari/session.h"

#include "tcpsocket.h"

namespace ari {
std::shared_ptr<Session> Session::Make(const int64_t id) {
    return std::make_shared<Session>(id);
}
Session::Session(const int64_t id)
    : _id(id),
      _socket(std::make_unique<TcpSocket>()) {}  // TODO: select udp, tcp

Session::~Session() {}
}  // namespace ari
