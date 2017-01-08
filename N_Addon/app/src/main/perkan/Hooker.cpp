#include "Hooker.h"
#include "CustomMinecraftClient.h"
#include "CustomRakNetInstance.h"

Hooker::Hooker() {
    client = 0;
    CustomMinecraftClient::hook();
    CustomRakNetInstance::hook();
}

Hooker::~Hooker() {

}

void Hooker::setClient(MinecraftClient *client) {
    this->client = client;
}

MinecraftClient* Hooker::getClient() const {
    return client;
}

void Hooker::hook() {

}