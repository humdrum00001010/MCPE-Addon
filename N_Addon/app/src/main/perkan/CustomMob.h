//
// Created by humdr on 2017-01-09.
//

#ifndef N_ADDON_CUSTOMMOB_H
#define N_ADDON_CUSTOMMOB_H

class Mob;

class Level;

class EntityDefinitionGroup;

class EntityDefinitionIdentity;

class CustomMob {
public:
	static void(*constructor1_real)(Mob *, Level *);

	static void constructor1(Mob *thiz, Level *level);

	static void(*constructor2_real)(Mob *, EntityDefinitionGroup *, EntityDefinitionIdentity *);

	static void constructor2(Mob *thiz, EntityDefinitionGroup *group,
	                         EntityDefinitionIdentity *identity);

	static void(*destructor_real)(Mob *);

	static void destructor(Mob *thiz);

	static void hook();
};

#endif //N_ADDON_CUSTOMMOB_H
