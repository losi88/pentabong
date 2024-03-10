
#pragma once

#include "ari/ari.h"

namespace ari
{
class Session;
} // namespace ari

class Player : public std::enable_shared_from_this<Player> {
public:
    Player(std::shared_ptr<ari::Session> session);

private:
    const int64_t _id;
    std::weak_ptr<ari::Session> _session;
};
