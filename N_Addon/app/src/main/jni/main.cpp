#include <jni.h>
#include <vars.h>
#include "../header/entity/Mob.h"

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    g_JavaVM = vm;
    return JNI_VERSION_1_6;
}