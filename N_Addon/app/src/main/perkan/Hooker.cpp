#include "Hooker.h"
#include "CustomMinecraftClient.h"
#include "CustomRakNetInstance.h"
#include "CustomMob.h"

Hooker::Hooker() {
	client = 0;
	mobs = std::vector<Mob *>();
	players = std::vector<Player *>();
	CustomMinecraftClient::hook();
	CustomRakNetInstance::hook();
	CustomMob::hook();
}

Hooker::~Hooker() {

}

void Hooker::setClient(MinecraftClient *client) {
	this->client = client;
}

MinecraftClient *Hooker::getClient() const {
	return client;
}

void Hooker::hook() {

}