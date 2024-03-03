
#pragma once

#include "ari/socket.h"

namespace ari {
class TcpSocket : public Socket {
public:
    virtual ~TcpSocket();
};
}  // namespace ari
