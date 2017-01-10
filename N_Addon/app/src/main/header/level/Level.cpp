//
// Created by humdr on 2017-01-10.
//

#include <macro.h>
#include "Level.h"

std::vector<Player*>& Level::getPlayers() {
	return access(std::vector<Player*>, this, OFFSET::PLAYERS);
}