#pragma once
#ifndef VARS_H_
#define VARS_H_

#include "../perkan/Hooker.h"

#ifndef JNI_H_

#include <jni.h>

#endif
extern JavaVM *bl_JavaVM;
extern jclass bl_scriptmanager_class;

class Var {
    static JavaVM *g_JavaVM;
    static Hooker *hooker;

    static class JavaClasses {
    public:
        class JNI_Class {
        private:
            const char *className;
            jclass thiz;
        public:
            JNI_Class(const char *className);

            virtual ~JNI_Class();

        public:
            void initialize(JNIEnv **env);

            void setClassName(const char *name);

            jclass &get();
        };

        class Class : public JNI_Class {
        public:
            Class(const char *className) : JNI_Class(className) { }
        } *Class_class;

        class ClassLoader : public JNI_Class {
        public:
            ClassLoader(const char *className) : JNI_Class(className) { }
        } *ClassLoader_class;

        class DexClassLoader : public JNI_Class {
        public:
            DexClassLoader(const char *className) : JNI_Class(className) { }
        } *DexClassLoader_class;

        class ScriptState : public JNI_Class {
        public:
            ScriptState(const char *className) : JNI_Class(className) { }
        } *ScriptState_class;

        class ScriptableObject : public JNI_Class {
        public:
            ScriptableObject(const char *className) : JNI_Class(className) { }
        } *ScriptableObject_class;

        class MainActivity : public JNI_Class {
        public:
            MainActivity(const char *className) : JNI_Class(className) { }
        } *MainActivity_class;

        class Reference : public JNI_Class {
        public:
            Reference(const char *className) : JNI_Class(className) { }
        } *Reference_class;

        class List : public JNI_Class {
        public:
            List(const char *className) : JNI_Class(className) { }
        } *List_class;

        class Utils : public JNI_Class {
        public:
            Utils(const char *className) : JNI_Class(className) { }
        } *Utils_class;

        class Set : public JNI_Class {
        public:
            Set(const char *className) : JNI_Class(className) { }
        } *Set_class;

        class Object : public JNI_Class {
        public:
            Object(const char *className) : JNI_Class(className) { }
        } *Object_class;

    public:
        JavaClasses(JNIEnv **env);

        ~JavaClasses();
    } *javaClasses;

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
    static void setJavaVM(JavaVM *vm);

    static JavaVM *getJavaVM();

    static void setHooker(Hooker *hooker);

    static Hooker *getHooker();

    static void deleteHooker();

    static void initJavaClasses(JNIEnv **env);

    static JavaClasses *getJavaClassGroup();

    static Flag &getFlag();
};

#endif