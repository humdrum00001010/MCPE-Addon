#pragma once

#include "../network/protocol/Packet.h"

class ContainerSetDataPacket : public Packet {
public:
	virtual ~ContainerSetDataPacket();
	virtual char getId() const;
	virtual void write(BinaryStream&) const;
	virtual void read(BinaryStream&);
	virtual void handle(const NetworkIdentifier&, NetEventCallback&) const;
};