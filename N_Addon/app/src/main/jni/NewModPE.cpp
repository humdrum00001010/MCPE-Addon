//
// Created by humdr on 2017-01-08.
//

#include <thread>
#include <fstream>
#include <sstream>
#include "NewModPE.h"
#include "vars.h"

std::vector<ClassInfo> NewModPE::classArray;

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

void NewModPE::callHook(JNIEnv **pEnv, const char *hookName, jobjectArray objArray) {
	(*pEnv)->CallStaticVoidMethod(bl_scriptmanager_class,
	                              (*pEnv)->GetStaticMethodID(bl_scriptmanager_class,
	                                                         "callScriptMethod",
	                                                         "(Ljava/lang/String;[Ljava/lang/Object;)V"),
	                              (*pEnv)->NewStringUTF(hookName), objArray);
}

void NewModPE::loadDex(JNIEnv **pEnv, const char *dexPath, const char *dexPath_dummy,
                       const char *n_className,
                       JNINativeMethod *function_implement, int JNI_s, jclass *globalRef) {
	jobject ClassLoader = (*pEnv)->CallObjectMethod(
			Var::getJavaClassGroup()->MainActivity_class->get(),
			(*pEnv)->GetMethodID(Var::getJavaClassGroup()->Class_class->get(), "getClassLoader",
			                     "()Ljava/lang/ClassLoader;"));
	jobject DexClassLoader = (*pEnv)->NewObject(
			Var::getJavaClassGroup()->DexClassLoader_class->get(),
			(*pEnv)->GetMethodID(Var::getJavaClassGroup()->DexClassLoader_class->get(), "<init>",
			                     "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)V"),
			(*pEnv)->NewStringUTF(dexPath), (*pEnv)->NewStringUTF(dexPath_dummy), 0, ClassLoader);
	jclass n_jsClass = (jclass) (*pEnv)->CallStaticObjectMethod(
			Var::getJavaClassGroup()->Class_class->get(),
			(*pEnv)->GetStaticMethodID(Var::getJavaClassGroup()->Class_class->get(), "forName",
			                           "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;"),
			(*pEnv)->NewStringUTF(n_className), true, DexClassLoader);
	(*pEnv)->RegisterNatives(n_jsClass, function_implement, JNI_s);
	*globalRef = (jclass) ((*pEnv)->NewGlobalRef(n_jsClass));
	(*pEnv)->DeleteLocalRef(n_jsClass);
	std::vector<std::string> vects = split(n_className, '.');
	classArray.push_back({ globalRef, (vects[vects.size() - 1]).c_str() });
}

void NewModPE::init(JNIEnv **pEnv, jclass *javaClass, const char *javaClassName) {
	jobject MainActivity = (*pEnv)->CallObjectMethod(
			(*pEnv)->GetStaticObjectField(Var::getJavaClassGroup()->MainActivity_class->get(),
			                              (*pEnv)->GetStaticFieldID(
					                              Var::getJavaClassGroup()->MainActivity_class->get(),
					                              "currentMainActivity",
					                              "Ljava/lang/ref/WeakReference;")),
			(*pEnv)->GetMethodID(Var::getJavaClassGroup()->Reference_class->get(), "get",
			                     "()Ljava/lang/Object;"));
	jfieldID MainActivity$displayMetricsGet = (*pEnv)->GetFieldID(
			Var::getJavaClassGroup()->MainActivity_class->get(), "displayMetrics",
			"Landroid/util/DisplayMetrics;");
	jobject ScriptManager$scripts = (*pEnv)->GetStaticObjectField(bl_scriptmanager_class,
	                                                              (*pEnv)->GetStaticFieldID(
			                                                              bl_scriptmanager_class,
			                                                              "scripts",
			                                                              "Ljava/util/List;"));
	jmethodID List$size = (*pEnv)->GetMethodID(Var::getJavaClassGroup()->List_class->get(), "size",
	                                           "()I");
	jint scriptLength = (*pEnv)->CallIntMethod(
			(*pEnv)->CallStaticObjectMethod(Var::getJavaClassGroup()->Utils_class->get(),
			                                (*pEnv)->GetStaticMethodID(
					                                Var::getJavaClassGroup()->Utils_class->get(),
					                                "getEnabledScripts", "()Ljava/util/Set;")),
			(*pEnv)->GetMethodID(Var::getJavaClassGroup()->Set_class->get(), "size", "()I"));
	while ((*pEnv)->CallIntMethod(ScriptManager$scripts, List$size) < scriptLength);
	jint scripts$size = (*pEnv)->CallIntMethod(ScriptManager$scripts, List$size);
	jmethodID List$get = (*pEnv)->GetMethodID(Var::getJavaClassGroup()->List_class->get(), "get",
	                                          "(I)Ljava/lang/Object;");
	jfieldID ScriptState$scope = (*pEnv)->GetFieldID(
			Var::getJavaClassGroup()->ScriptState_class->get(), "scope",
			"Lorg/mozilla/javascript/Scriptable;");
	jmethodID ScriptableObject$hasProperty = (*pEnv)->GetStaticMethodID(
			Var::getJavaClassGroup()->ScriptableObject_class->get(), "hasProperty",
			"(Lorg/mozilla/javascript/Scriptable;Ljava/lang/String;)Z");
	jmethodID ScriptableObject$defineClass = (*pEnv)->GetStaticMethodID(
			Var::getJavaClassGroup()->ScriptableObject_class->get(), "defineClass",
			"(Lorg/mozilla/javascript/Scriptable;Ljava/lang/Class;Z)V");

	for (int i = 0; i < scripts$size; i++) {
		jobject scripts$scope = (*pEnv)->GetObjectField(
				(*pEnv)->CallObjectMethod(ScriptManager$scripts, List$get, i), ScriptState$scope);
		if (!((*pEnv)->CallStaticBooleanMethod(
				Var::getJavaClassGroup()->ScriptableObject_class->get(),
				ScriptableObject$hasProperty, scripts$scope,
				(*pEnv)->NewStringUTF(javaClassName)))) {
			(*pEnv)->CallStaticVoidMethod(Var::getJavaClassGroup()->ScriptableObject_class->get(),
			                              ScriptableObject$defineClass, scripts$scope, *javaClass,
			                              true);
		}
	}

	callHook(pEnv, "onNewModPELoaded",
	         (*pEnv)->NewObjectArray(0, Var::getJavaClassGroup()->Object_class->get(), 0));
}

void NewModPE::initializeAllModPE() {
	JNIEnv *env = 0;
	int attachStatus = bl_JavaVM->GetEnv((void **) &env, JNI_VERSION_1_2);
	if (attachStatus == JNI_EDETACHED)
		bl_JavaVM->AttachCurrentThread(&env, 0);
	for (ClassInfo info : classArray) {
		NewModPE::init(&env, info.g_class, info.className);
	}
	if (attachStatus == JNI_EDETACHED)
		bl_JavaVM->DetachCurrentThread();
}

void NewModPE::registerClass(ClassInfo info) {
	classArray.push_back(info);
}

void NewModPE::start() {
	std::thread thr(initializeAllModPE);
	thr.detach();
}