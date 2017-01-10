#pragma once

#include <string>

#include "Packet.h"

// Size: 16
class DisconnectPacket : public Packet {
public:
	std::string message;    // 12-16

	DisconnectPacket(const char *str) : message(str) { }

	DisconnectPacket(std::string const &str) : message(str) { }

	virtual ~DisconnectPacket() { }

	virtual int getId() const;

	virtual void write(BinaryStream &) const;

	virtual void read(BinaryStream &);

	virtual void handle(NetworkIdentifier const &, NetEventCallback const &) const;
};