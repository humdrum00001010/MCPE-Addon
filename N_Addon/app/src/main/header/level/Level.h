//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_LEVEL_H
#define N_ADDON_LEVEL_H
#include <vector>
#include <memory>
class Player;
class Level {
public:
	enum class OFFSET {
		PLAYERS = 0x18
	};

	std::vector<Player*> &getPlayers();
};
#endif //N_ADDON_LEVEL_H
