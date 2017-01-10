//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_MINECRAFT_H
#define N_ADDON_MINECRAFT_H
#include "../network/sender/BatchedPacketSender.h"
#include "../level/Level.h"
class Minecraft {
public:
    PacketSender getPacketSender();
	Level* getLevel();
};
#endif //N_ADDON_MINECRAFT_H
