//
// Created by humdr on 2017-01-09.
//

#include "BatchedPacketSender.h"
#include "../../client/MinecraftPackets.h"

void BatchedPacketSender::sendTextPacket(TextPacket::TextPacketType mode, const char *sender,
                                         const char *msg) {
	TextPacket packet(mode, sender, msg);
	send(packet);
}

void BatchedPacketSender::sendTextPacket(TextPacket::TextPacketType mode, const char *sender,
                                         const char *msg, NetworkIdentifier &identifier) {
	TextPacket packet(mode, sender, msg);
	send(identifier, packet);
}

void BatchedPacketSender::sendDisconnectPacket(const char *reason) {
	DisconnectPacket packet = reason;
	send(packet);
}

void BatchedPacketSender::sendDisconnectPacket(const char *reason,
                                               NetworkIdentifier &identifier) {
	DisconnectPacket packet = reason;
	send(identifier, packet);
}