//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_CUSTOMMINECRAFTCLIENT_H
#define N_ADDON_CUSTOMMINECRAFTCLIENT_H

#include "../header/client/MinecraftClient.h"
#include "../header/entity/player/Player.h"

class CustomMinecraftClient {
public:
	static void(*constructor_real)(MinecraftClient *, int argc, char **argv);

	static void constructor(MinecraftClient *thiz, int argc, char **argv);

	static void(*destructor_real)(MinecraftClient *thiz);

	static void destructor(MinecraftClient *thiz);

	static void(*init_real)(MinecraftClient *thiz);

	static void init(MinecraftClient *thiz);

	static void(*onPlayerLoaded_real)(MinecraftClient *thiz, Player *player);

	static void onPlayerLoaded(MinecraftClient *thiz, Player *player);

	static void(*leaveGame_real)(MinecraftClient *thiz, bool join);

	static void leaveGame(MinecraftClient *thiz, bool join);

	static void hook();
};

#endif //N_ADDON_CUSTOMMINECRAFTCLIENT_H
