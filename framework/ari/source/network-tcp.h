
#pragma once

#include <unordered_map>
#include <mutex>
#include <thread>

#include "asio.hpp"
#include "ari/network.h"

namespace ari {
class Acceptor;
class SessionManager;
class Session;
}  // namespace ari

namespace ari {
class Network_TCP : public Network {
private:
    struct AcceptorKey {
        const IP ip;
        const int port;

        struct Hasher {
            size_t operator()(const AcceptorKey& rhs) const;
        };

        struct EqualTo {
            bool operator()(const AcceptorKey& lhs,
                            const AcceptorKey& rhs) const;
        };
    };

public:
    Network_TCP(const std::shared_ptr<const NetworkHandler>& networkHandler);
    Network_TCP(const Network_TCP&) = delete;
    Network_TCP(Network_TCP&&) = delete;
    virtual ~Network_TCP();

public:
    virtual bool OpenPort(const IP ip, const int port) override final;
    virtual bool ClosePort(const IP ip, const int port) override final;

public:
    virtual bool Connect(const char* host, const char* port) override final;

public:
    void OnAccepted(std::unique_ptr<Session> session) const;
    void OnReceived(const Session& session, const size_t size,
                    const char* data) const;
    void OnClosed(const Session& session) const;

public:
    void OnConnected(std::unique_ptr<Session> session) const;

private:
    // _acceptorMapMtx
    bool insertAcceptor(const AcceptorKey& key, const std::shared_ptr<Acceptor>& acceptor);
    // _acceptorMapMtx
    bool eraseAcceptor(const AcceptorKey& key);

private:
    typedef std::unordered_map<AcceptorKey, std::shared_ptr<Acceptor>,
                               AcceptorKey::Hasher, AcceptorKey::EqualTo>
        AcceptorMap;

    const std::shared_ptr<const NetworkHandler> _networkHandler;
    const std::unique_ptr<SessionManager> _sessionManager;
    
    asio::io_context _ioContext;
    std::thread* _ioContextThread;

    std::mutex _acceptorMapMtx;
    AcceptorMap _acceptorMap;
};
}  // namespace ari
