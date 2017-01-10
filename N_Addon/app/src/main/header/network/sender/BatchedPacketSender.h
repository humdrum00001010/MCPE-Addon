//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_BATCHEDPACKETSENDER_H
#define N_ADDON_BATCHEDPACKETSENDER_H

#include "../protocol/TextPacket.h"
#include "../protocol/DisconnectPacket.h"
#include "../../entity/player/Player.h"
#include <memory>

class NetworkHandler;

class BatchedPacketSender {
public:
	virtual ~BatchedPacketSender();

	virtual void send(Packet const &);

	virtual void send(NetworkIdentifier const &, Packet const &);

	virtual void sendBroadcast(NetworkIdentifier const &, Packet const &);

	virtual void sendBroadcast(Packet const &);

	virtual void flush(NetworkIdentifier const &);

	BatchedPacketSender(NetworkHandler &);

	/* BatchPacket* */ void _getBatch(NetworkIdentifier const &);

	bool _playerExists(NetworkIdentifier const &) const;

	void _queuePacket(NetworkIdentifier const &, Packet const &);

	void addLoopbackCallback(NetEventCallback &);

	void removeLoopbackCallback(NetEventCallback &);

	void setPlayerList(std::vector<std::unique_ptr<Player>> const *);

	void update();

	void sendTextPacket(TextPacket::TextPacketType mode, const char *sender, const char *msg);

	void sendTextPacket(TextPacket::TextPacketType mode, const char *sender, const char *msg,
	                    NetworkIdentifier &identifier);

	void sendDisconnectPacket(const char *reason);

	void sendDisconnectPacket(const char *reason, NetworkIdentifier &identifier);
};

typedef BatchedPacketSender *PacketSender;
#endif //N_ADDON_BATCHEDPACKETSENDER_H
