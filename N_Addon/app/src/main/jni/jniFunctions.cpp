//
// Created by humdr on 2017-01-08.
//

#include "jniFunctions.h"
#include "vars.h"

int JniFunctions::test() {
    JNIEnv* env = 0;
    int attachStatus = g_JavaVM->GetEnv((void**)&env, JNI_VERSION_1_6);
    if (attachStatus == JNI_EDETACHED) g_JavaVM->AttachCurrentThread(&env, 0);
    
    if (attachStatus == JNI_EDETACHED) g_JavaVM->DetachCurrentThread();
}
