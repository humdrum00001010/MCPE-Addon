//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_TEXTPACKET_H
#define N_ADDON_TEXTPACKET_H

#include "Packet.h"
#include <string>
#include <vector>

class TextPacket : public Packet {
public:
	enum class TextPacketType {
		RAW,
		CHAT,
		TRANSLATION,
		POPUP,
		TIP,
		SYSTEM,
		WHISPER
	};
	TextPacketType type; // 12
	std::string sender; // 16
	std::string msg; // 20
	std::vector<std::string> params; // 24

public:
	TextPacket() : type(TextPacketType::RAW), sender(""), msg(msg), params() { }

	TextPacket(TextPacketType mode, std::string const &sender, std::string const &msg) : type(mode),
	                                                                                     sender(sender),
	                                                                                     msg(msg) { }

	TextPacket(TextPacketType mode, std::string const &sender, std::string const &msg,
	           std::vector<std::string> const &params) : type(mode), sender(sender), msg(msg),
	                                                     params(params) { }

	virtual ~TextPacket() { };

	virtual int getId() const;

	virtual void write(BinaryStream &) const;

	virtual void read(BinaryStream &);

	virtual void handle(NetworkIdentifier const &, NetEventCallback const &) const;

	static TextPacket *createRaw(std::string const &);

	static TextPacket *createSystemMessage(std::string const &);

	static TextPacket *createTranslated(std::string const &, std::vector<std::string> const &);
};

#endif //N_ADDON_TEXTPACKET_H
