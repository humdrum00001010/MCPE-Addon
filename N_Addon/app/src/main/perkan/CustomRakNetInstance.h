//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_CUSTOMRAKNETINSTANCE_H
#define N_ADDON_CUSTOMRAKNETINSTANCE_H

#include "../header/utils/social/Social.h"
#include "../header/network/raknet/RakNetInstance.h"

class CustomRakNetInstance {
public:
	static void(*connect_real)(RakNetInstance *, Social::GameConnectionInfo const &,
	                           Social::GameConnectionInfo const &);

	static void connect(RakNetInstance *thiz, Social::GameConnectionInfo const &myInfo,
	                    Social::GameConnectionInfo const &targetInfo);

	static void hook();
};

#endif //N_ADDON_CUSTOMRAKNETINSTANCE_H
