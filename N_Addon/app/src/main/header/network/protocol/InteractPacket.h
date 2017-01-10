//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_INTERACTPACKET_H
#define N_ADDON_INTERACTPACKET_H
#include "Packet.h"
class InteractPacket : public Packet {
public:
    unsigned char type; // 12
    EntityRuntimeID runtimeID; // 16

public:
    virtual ~InteractPacket();
    virtual int getId() const;
    virtual void write(BinaryStream&) const;
    virtual void read(BinaryStream&);
    virtual void handle(NetworkIdentifier const&, NetEventCallback const&) const;
};
#endif //N_ADDON_INTERACTPACKET_H
