
#include "player.h"

#include "ari/session.h"

Player::Player(std::shared_ptr<ari::Session> session)
    : _id(session->ID()), _session(session) {}
