//
// Created by humdr on 2017-01-08.
//

#include "vars.h"

JavaVM *Var::g_JavaVM = 0;
Hooker *Var::hooker = 0;
Var::Flag Var::flag = Var::Flag();
Var::JavaClasses *Var::javaClasses = 0;

void Var::setJavaVM(JavaVM *vm) {
    g_JavaVM = vm;
}

JavaVM *Var::getJavaVM() {
    return g_JavaVM;
}

void Var::setHooker(Hooker *hooker) {
    Var::hooker = hooker;
}

Hooker *Var::getHooker() {
    return hooker;
}

void Var::deleteHooker() {
    delete hooker;
}

void Var::initJavaClasses(JNIEnv **env) {
    Var::javaClasses = new JavaClasses(env);
}

Var::JavaClasses *Var::getJavaClassGroup() {
    return javaClasses;
}

Var::Flag &Var::getFlag() {
    return flag;
}

Var::JavaClasses::JNI_Class::JNI_Class(const char *className) {
    setClassName(className);
}

Var::JavaClasses::JNI_Class::~JNI_Class() {
    delete className;
}

void Var::JavaClasses::JNI_Class::setClassName(const char *name) {
    className = name;
}

void Var::JavaClasses::JNI_Class::initialize(JNIEnv **env) {
    jclass tmpClass = (*env)->FindClass(className);
    thiz = (jclass) (*env)->NewGlobalRef(tmpClass);
    (*env)->DeleteLocalRef(tmpClass);
}

jclass &Var::JavaClasses::JNI_Class::get() {
    return thiz;
}

Var::JavaClasses::JavaClasses(JNIEnv **env) {
    Class_class = new Class("java/lang/Class");
    Class_class->initialize(env);
    ClassLoader_class = new ClassLoader("java/lang/ClassLoader");
    ClassLoader_class->initialize(env);
    DexClassLoader_class = new DexClassLoader("dalvik/system/DexClassLoader");
    DexClassLoader_class->initialize(env);
    ScriptState_class = new ScriptState("net/zhuoweizhang/mcpelauncher/ScriptManager$ScriptState");
    ScriptState_class->initialize(env);
    ScriptableObject_class = new ScriptableObject("org/mozilla/javascript/ScriptableObject");
    ScriptableObject_class->initialize(env);
    MainActivity_class = new MainActivity("com/mojang/minecraftpe/MainActivity");
    MainActivity_class->initialize(env);
    Reference_class = new Reference("java/lang/ref/Reference");
    Reference_class->initialize(env);
    List_class = new List("java/util/List");
    List_class->initialize(env);
    Utils_class = new Utils("net/zhuoweizhang/mcpelauncher/Utils");
    Utils_class->initialize(env);
    Set_class = new Set("java/util/Set");
    Set_class->initialize(env);
    Object_class = new Object("java/lang/Object");
    Object_class->initialize(env);
}

Var::JavaClasses::~JavaClasses() {
    delete Class_class;
    delete ClassLoader_class;
    delete DexClassLoader_class;
    delete ScriptState_class;
    delete ScriptableObject_class;
    delete MainActivity_class;
    delete Reference_class;
    delete List_class;
    delete Utils_class;
    delete Set_class;
    delete Object_class;
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