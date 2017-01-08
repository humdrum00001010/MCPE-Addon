//
// Created by humdr on 2017-01-08.
//

#include <mcpelauncher.h>
#include <vars.h>
#include "CustomRakNetInstance.h"

void(*CustomRakNetInstance::connect_real)(RakNetInstance*, Social::GameConnectionInfo const&,
                                          Social::GameConnectionInfo const&);
void CustomRakNetInstance::connect(RakNetInstance *thiz, Social::GameConnectionInfo const &myInfo,
                                   Social::GameConnectionInfo const &targetInfo) {
    connect_real(thiz, myInfo, targetInfo);
    Var::getFlag().setInServer(true);
}

void CustomRakNetInstance::hook() {
    MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN14RakNetInstance7connectEN6Social18GameConnectionInfoES1_"), (void*)&CustomRakNetInstance::connect, (void**)&CustomRakNetInstance::connect_real);
}