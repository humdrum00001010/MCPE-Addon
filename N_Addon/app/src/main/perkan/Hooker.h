#pragma once

#ifndef HOOKER_H_

#include "../header/client/MinecraftClient.h"

#define HOOKER_H_

class Hooker {
	MinecraftClient *client;
public:
	std::vector<Mob *> mobs;
	std::vector<Player *> players;
public:
	Hooker();

	~Hooker();

	void setClient(MinecraftClient *client);

	MinecraftClient *getClient() const;

	void hook();
};

#endif