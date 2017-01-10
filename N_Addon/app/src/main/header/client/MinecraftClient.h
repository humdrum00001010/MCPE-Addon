#pragma once

#ifndef MINECRAFTCLIENT_H_
#define MINECRAFTCLIENT_H_
#include "gui/GuiData.h"
#include "Minecraft.h"
class MinecraftClient {
public:
    void init();
    GuiData* getGuiData();
	Minecraft* getServer();
};
#endif