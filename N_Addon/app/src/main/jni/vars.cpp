//
// Created by humdr on 2017-01-08.
//

#include "vars.h"

Hooker* Var::hooker = new Hooker();
Var::Flag Var::flag = Var::Flag();
Var::JavaClasses Var::javaClasses = Var::JavaClasses();

void Var::setHooker(Hooker *hooker) {
    Var::hooker = hooker;
}

Hooker* Var::getHooker() {
    return hooker;
}

void Var::deleteHooker() {
    delete hooker;
}

Var::JavaClasses& Var::getJavaClassGroup() {
    return javaClasses;
}

Var::Flag& Var::getFlag() {
    return flag;
}

Var::JavaClasses::JavaClasses() {
    Test = 0;
}

Var::JavaClasses::~JavaClasses() {

}

Var::Flag::Flag() {
    inGame = false;
    inServer = false;
}

Var::Flag::~Flag() {

}

void Var::Flag::setInGame(bool logic) {
    inGame = logic;
}

bool Var::Flag::getInGame() const {
    return inGame;
}

void Var::Flag::setInServer(bool logic) {
    inServer = logic;
}

bool Var::Flag::getInServer() const {
    return inServer;
}