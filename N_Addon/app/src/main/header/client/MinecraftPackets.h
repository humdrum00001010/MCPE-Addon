//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_MINECRAFTPACKETS_H
#define N_ADDON_MINECRAFTPACKETS_H
class Packet;
class MinecraftPackets {
public:
    Packet* retval; // 0

    enum class PacketId {
        LOGIN,
        DISCONNECT = 0x5,
        TextPacket = 0xA
    };

public:
    Packet* createPacket(int);

    static Packet* newPacket(int id);
};
#endif //N_ADDON_MINECRAFTPACKETS_H
