
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
    virtual ~SessionManager();

public:
    std::shared_ptr<Session> CreateSession();
    void DeleteSession(const int64_t id);

private:
    typedef std::unordered_map<int64_t, std::shared_ptr<Session>> SessionMap;

    std::atomic_int64_t _idGenerator;
    SessionMap _sessionMap;
};
}  // namespace ari
