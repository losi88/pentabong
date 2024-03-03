
#include "ari/sessionmanager.h"

#include "ari/session.h"

namespace ari {
SessionManager::SessionManager() : _idGenerator(0), _sessionMap() {}

SessionManager::~SessionManager() {}

std::shared_ptr<Session> SessionManager::CreateSession() {
    const auto id = ++_idGenerator;

    auto session = Session::Make(id);
    _sessionMap.insert(std::make_pair(id, session));

    return session;
}

void SessionManager::DeleteSession(const int64_t id) { _sessionMap.erase(id); }
}  // namespace ari
