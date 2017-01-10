#include <vars.h>
#include "NewModPE.h"

#define WRITE "w"
#define READ "r"
#define DEX_PATH "/sdcard/games/com.mojang/JSLib.dex"
#define DEX_DUMMY_PATH "/data/data/net.zhuoweizhang.mcpelauncher/files/"

#include <stdio.h>

static jclass DefaultLibrary;

JNIEXPORT void JNICALL nativeSendTextPacket(JNIEnv *env, jobject *jobj, jint type, jstring sender,
                                            jstring content) {
	const char *arg4 = env->GetStringUTFChars(sender, 0);
	const char *arg5 = env->GetStringUTFChars(content, 0);

	Var::getHooker()->getClient()->getServer()->getPacketSender()->sendTextPacket(
			(TextPacket::TextPacketType) type, arg4, arg5);
}

JNIEXPORT jstring JNICALL nativeGetPlayerName(JNIEnv *env, jobject *obj, int eid) {
	
}

#include "macro.h"

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
	Var::setJavaVM(vm);
	Var::setHooker(new Hooker());
	JNIEnv *env = 0;
	FILE *dexFile;
	if ((dexFile = fopen(DEX_PATH, READ)) != 0) {
		fclose(dexFile);
		int attachStatus = bl_JavaVM->GetEnv((void **) &env, JNI_VERSION_1_2);
		if (attachStatus == JNI_EDETACHED)
			bl_JavaVM->AttachCurrentThread(&env, 0);
		Var::initJavaClasses(&env);
		JNINativeMethod methods[] = {
				{ "nativeSendTextPacket", "(ILjava/lang/String;Ljava/lang/String;)V", (void *) nativeSendTextPacket },
				{ "nativeGetPlayerName",  "(I)Ljava/lang/String;",                    (void *) nativeGetPlayerName }
		};
		NewModPE::loadDex(&env, DEX_PATH, DEX_DUMMY_PATH, "com.perkan.newclass.DefaultLibrary",
		                  methods, sizeof(methods) / sizeof(JNINativeMethod), &DefaultLibrary);
		if (attachStatus == JNI_EDETACHED)
			bl_JavaVM->DetachCurrentThread();
		NewModPE::start();
	}

	return JNI_VERSION_1_2;
}