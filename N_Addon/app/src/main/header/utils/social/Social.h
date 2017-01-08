//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_SOCIAL_H
#define N_ADDON_SOCIAL_H
#include "../../network/raknet/RakNet.h"
#include "../web/web.h"
namespace Social {
    class GameConnectionInfo {
    public:
        GameConnectionInfo(RakNet::SystemAddress);
        ~GameConnectionInfo();
        void fromJson(web::json::value const&);
        web::json::value toJson() const;
        const char* typeAsString() const;
    };
}
#endif //N_ADDON_SOCIAL_H