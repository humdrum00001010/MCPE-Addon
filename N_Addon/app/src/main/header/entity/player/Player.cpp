//
// Created by humdr on 2017-01-09.
//

#include "../../../jni/macro.h"
#include "Player.h"

NetworkIdentifier& Player::getNetworkIdentifier() {
    return access(NetworkIdentifier, this, OFFSET::NETWORKIDENTIFIER);
}