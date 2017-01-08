//
// Created by humdr on 2017-01-08.
//

#include <vars.h>
#include <mcpelauncher.h>
#include "CustomMinecraftClient.h"

void(*CustomMinecraftClient::constructor_real)(MinecraftClient* thiz, int argc, char** argv);
void CustomMinecraftClient::constructor(MinecraftClient *thiz, int argc, char **argv) {
    constructor_real(thiz, argc, argv);
}

void(*CustomMinecraftClient::destructor_real)(MinecraftClient* thiz);
void CustomMinecraftClient::destructor(MinecraftClient *thiz) {
    destructor_real(thiz);
    Var::deleteHooker();
}

void(*CustomMinecraftClient::init_real)(MinecraftClient* thiz);
void CustomMinecraftClient::init(MinecraftClient *thiz) {
    Var::getHooker()->setClient(thiz);
    init_real(thiz);
}

void(*CustomMinecraftClient::onPlayerLoaded_real)(MinecraftClient* thiz, Player* player);
void CustomMinecraftClient::onPlayerLoaded(MinecraftClient *thiz, Player *player) {
    onPlayerLoaded_real(thiz, player);
    Var::getFlag().setInGame(true);
}

void(*CustomMinecraftClient::leaveGame_real)(MinecraftClient* thiz, bool join);
void CustomMinecraftClient::leaveGame(MinecraftClient *thiz, bool join) {
    leaveGame_real(thiz, join);
    Var::getFlag().setInGame(false);
    Var::getFlag().setInServer(false);
}

void CustomMinecraftClient::hook() {
    MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClientC2EiPPc"), (void*)&constructor, (void**)&constructor_real);
    MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClientD2Ev"), (void*)&destructor, (void**)&destructor_real);
    MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClient4initEv"), (void*)&init, (void**)&init_real);
    MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClient14onPlayerLoadedER6Player"), (void*)&onPlayerLoaded, (void**)&onPlayerLoaded_real);
    MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClient9leaveGameEb"), (void*)&CustomMinecraftClient::leaveGame, (void**)&CustomMinecraftClient::leaveGame_real);
}