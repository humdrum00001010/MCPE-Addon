//
// Created by humdr on 2017-01-09.
//

#include <mcpelauncher.h>
#include <vars.h>
#include "CustomMob.h"

void(*CustomMob::constructor1_real)(Mob *, Level *);

void CustomMob::constructor1(Mob *thiz, Level *level) {
	Var::getHooker()->mobs.push_back(thiz);
	constructor1_real(thiz, level);
}

void(*CustomMob::constructor2_real)(Mob *, EntityDefinitionGroup *, EntityDefinitionIdentity *);

void CustomMob::constructor2(Mob *thiz, EntityDefinitionGroup *group,
                             EntityDefinitionIdentity *identity) {
	Var::getHooker()->mobs.push_back(thiz);
	constructor2_real(thiz, group, identity);
}

void(*CustomMob::destructor_real)(Mob *);

void CustomMob::destructor(Mob *thiz) {
	destructor_real(thiz);
	std::vector<Mob *> &mobs = Var::getHooker()->mobs;
	for (int index = 0, length = mobs.size(); index < length; index++) {
		if (mobs[index] == thiz)
			mobs.erase(mobs.begin() + index--), length--;
	}
}

void CustomMob::hook() {
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN3MobC2ER5Level"), (void *) &CustomMob::constructor1,
	               (void **) &CustomMob::constructor1_real);
	MSHookFunction(
			dlsym(RTLD_DEFAULT, "_ZN3MobC2ER21EntityDefinitionGroupRK26EntityDefinitionIdentifier"),
			(void *) &CustomMob::constructor2, (void **) &CustomMob::constructor2_real);
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN3MobD2Ev"), (void *) &CustomMob::destructor,
	               (void **) &CustomMob::destructor_real);
}