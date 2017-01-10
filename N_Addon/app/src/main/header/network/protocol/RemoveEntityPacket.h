#pragma once

#include "Packet.h"

class RemoveEntityPacket : public Packet {
public:
	long long eid; // 16
public:
	virtual ~RemoveEntityPacket() { };

	virtual int getId() const;

	virtual void write(BinaryStream &) const;

	virtual void read(BinaryStream &);

	virtual void handle(const NetworkIdentifier &, NetEventCallback const &) const;
};