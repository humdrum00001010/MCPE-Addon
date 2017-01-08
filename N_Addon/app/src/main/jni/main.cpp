#include <jni.h>
#include <vars.h>
#include "../header/entity/Mob.h"

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    g_JavaVM = vm;
    JNIEnv* env = 0;
    int attachStatus = vm->GetEnv((void**)&env, JNI_VERSION_1_6);
    if (attachStatus == JNI_EDETACHED) vm->AttachCurrentThread(&env, 0);
    Var::getJavaClassGroup().Test = env->FindClass("com.perkan.addon.n_addon");
    jmethodID Test$test = env->GetMethodID(Var::getJavaClassGroup().Test, "test", "(V)I");
    int value = env->CallStaticIntMethod(Var::getJavaClassGroup().Test, Test$test);
    if (attachStatus==JNI_EDETACHED) vm->DetachCurrentThread();
    return JNI_VERSION_1_6;
}