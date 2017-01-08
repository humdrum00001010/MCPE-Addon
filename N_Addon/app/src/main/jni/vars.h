#pragma once
#ifndef VARS_H_
#define VARS_H_

#include "../perkan/Hooker.h"

#ifndef JNI_H_
#include <jni.h>
#endif
extern JavaVM* bl_JavaVM;
extern JavaVM* g_JavaVM;
extern jclass bl_scriptmanager_class;

class Var {
    static Hooker* hooker;
    static class Flag {
        bool inGame;
        bool inServer;
    public:
        Flag();
        ~Flag();

        void setInGame(bool logic);
        bool getInGame() const;
        void setInServer(bool logic);
        bool getInServer() const;
    } flag;
public:
    static void setHooker(Hooker* hooker);
    static Hooker* getHooker();
    static void deleteHooker();
    static Flag& getFlag();
};
#endif