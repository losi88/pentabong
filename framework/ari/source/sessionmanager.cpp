
#include "ari/sessionmanager.h"

#include "ari/session.h"
#include "ari/socket.h"

namespace ari {
SessionManager::SessionManager() : _sessionMap() {
}

SessionManager::~SessionManager() {
    EraseSession();
}

std::shared_ptr<Session> SessionManager::InsertSession(
    std::unique_ptr<Session> session) {
    if (nullptr == session) {
        // error: session is nullptr
        return nullptr;
    }

    auto id = session->ID();
    std::pair<SessionMap::iterator, bool> inserted =
        _sessionMap.insert(std::make_pair(id, std::move(session)));
    if (false == inserted.second) {
        // error: failed to insert
        return nullptr;
    }

    // info: insert session
    return inserted.first->second;
}

void SessionManager::EraseSession(const int64_t id) {
    _sessionMap.erase(id);
}

void SessionManager::EraseSession() {
    _sessionMap.clear();
}
}  // namespace ari
