//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_PLAYER_H
#define N_ADDON_PLAYER_H
#include "../Mob.h"
#include "../../network/NetworkIdentifier.h"

class Player : public Mob {
public:
    enum class OFFSET {
        NETWORKIDENTIFIER = 0xED8
    };

    NetworkIdentifier& getNetworkIdentifier();
};
#endif //N_ADDON_PLAYER_H
