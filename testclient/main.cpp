
#include <iostream>
#include <thread>

#include "ari/network.h"
#include "ari/session.h"
#include "ari/buffer.h"

std::shared_ptr<ari::Session> _Session = nullptr;

class NetworkHandler : public ari::NetworkHandler {
private:
    virtual void onAccepted(
        std::shared_ptr<ari::Session> session) const override final {
        std::cout << "accept(do not use)" << std::endl;
    }
    virtual void onReceived(std::shared_ptr<const ari::Session> session,
                            const size_t size,
                            const char* data) const override final {
        std::cout << "receive(" << session->ID() << "): " << data << "(" << size
                  << ")" << std::endl;
    }
    virtual void onClosed(
        std::shared_ptr<const ari::Session> session) const override final {
        std::cout << "close(" << session->ID() << ")" << std::endl;
    }
    virtual void onConnected(
        std::shared_ptr<ari::Session> session) const override final {
        std::cout << "connect(" << session->ID() << ")" << std::endl;
        _Session = session;
    }
};

std::shared_ptr<NetworkHandler> _NetworkHandler =
    std::make_shared<NetworkHandler>();

int main(int argc, int** argv) {
    std::thread t([]() {
        auto network = ari::Network::TCP(_NetworkHandler);
        network->Connect("localhost", "8080");
    });

    const size_t _MAX_LENGTH = 128;
    char line[_MAX_LENGTH];
    while (std::cin.getline(line, _MAX_LENGTH + 1)) {
        if (nullptr == _Session) {
            continue;
        }

        std::unique_ptr<ari::Buffer> buf =
            std::make_unique<ari::Buffer>(strlen(line), line);
        _Session->Write(std::move(buf));
    }

    t.join();
    return 0;
}
