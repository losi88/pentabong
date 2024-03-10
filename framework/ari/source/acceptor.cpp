
#include "acceptor.h"

#include "ari/network.h"
#include "ari/session.h"
#include "ari/sessionmanager.h"
#include "tcpsocket.h"

namespace ari {
Acceptor::Acceptor(asio::io_context& ioContext,
                   const asio::ip::tcp::endpoint& endPoint,
                   const std::shared_ptr<const NetworkHandler>& networkHandler)
    : _acceptor(ioContext, endPoint), _networkHandler(networkHandler) {
    accept();
}

Acceptor::~Acceptor() {}

void Acceptor::accept() {
    _acceptor.async_accept([this](std::error_code errorCode,
                                  asio::ip::tcp::socket socket) {
        if (!errorCode) {
            auto tcpSocket = std::make_unique<TcpSocket>(std::move(socket));
            auto session = _SessionManager.CreateSession(std::move(tcpSocket));
            _networkHandler->OnAccepted(session);
            session->Start();
        }

        accept();
    });
}

}  // namespace ari
