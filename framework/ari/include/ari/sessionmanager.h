
#pragma once

#include <atomic>
#include <unordered_map>

#include "ari/ari.h"

namespace ari {
class Session;
}  // namespace ari

namespace ari {
class ARI_API SessionManager {
public:
    SessionManager();
    SessionManager(const SessionManager&) = delete;
    SessionManager(SessionManager&&) = delete;
    virtual ~SessionManager();

public:
    std::shared_ptr<Session> InsertSession(Session* session);
    void EraseSession(const int64_t id);
    void EraseSession();

private:
    typedef std::unordered_map<int64_t, std::shared_ptr<Session>> SessionMap;

    SessionMap _sessionMap;
};
}  // namespace ari
