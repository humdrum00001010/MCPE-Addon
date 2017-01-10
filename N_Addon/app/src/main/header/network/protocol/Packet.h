//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_PACKET_H
#define N_ADDON_PACKET_H
class BinaryStream;
class NetworkIdentifier;
class NetEventCallback;
class Packet {
public:
    // void** vtable; // 0
    char filler1[8]; // 4

public:
    virtual ~Packet();
    virtual int getId() const = 0;
    virtual void write(BinaryStream&) const = 0;
    virtual void read(BinaryStream&) = 0;
    virtual void handle(NetworkIdentifier const&, NetEventCallback const&) const = 0;
    virtual bool disallowBatching();
};
#endif //N_ADDON_PACKET_H
