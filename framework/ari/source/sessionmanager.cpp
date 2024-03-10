
#include "ari/sessionmanager.h"

#include "ari/session.h"
#include "ari/socket.h"

namespace ari {
SessionManager::SessionManager() : _idGenerator(0), _sessionMap() {}

SessionManager::~SessionManager() {}

std::shared_ptr<Session> SessionManager::CreateSession(
    std::unique_ptr<Socket> socket) {
    const auto id = ++_idGenerator;

    auto session = Session::Make(id, std::move(socket));
    _sessionMap.insert(std::make_pair(id, session));

    return session;
}

void SessionManager::DeleteSession(const int64_t id) { _sessionMap.erase(id); }
}  // namespace ari
