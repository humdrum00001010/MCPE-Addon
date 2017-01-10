//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_NEWMODPE_H
#define N_ADDON_NEWMODPE_H

#include <jni.h>
#include <vector>

class ClassInfo {
public:
	jclass *g_class;
	const char *className;
};

class NewModPE {
	static std::vector<ClassInfo> classArray;
public:
	static void callHook(JNIEnv **pEnv, const char *hookName, jobjectArray objArray);

	static void loadDex(JNIEnv **pEnv, const char *dexPath, const char *dexPath_dummy,
	                    const char *n_className, JNINativeMethod function_implement[], int JNI_s,
	                    jclass *globalRef);

	static void init(JNIEnv **pEnv, jclass *javaClass, const char *javaClassName);

	static void initializeAllModPE();

	static void registerClass(ClassInfo info);

	static void start();
};

#endif //N_ADDON_NEWMODPE_H
