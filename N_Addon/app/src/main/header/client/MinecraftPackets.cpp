//
// Created by humdr on 2017-01-09.
//

#include "MinecraftPackets.h"

Packet* MinecraftPackets::newPacket(int id) {
    MinecraftPackets instance;
    return instance.createPacket(id);
}