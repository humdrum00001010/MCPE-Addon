LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := com.perkan.addon
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -ldl -llog -lstdc++ -lminecraftpe -lmcpelauncher_tinysubstrate -lmcpelauncher_new -lm -lc -lz

LOCAL_SRC_FILES :=                                   \
    main.cpp                                         \
    vars.cpp                                         \
    ../perkan/Hooker.cpp                             \
    ../perkan/CustomMinecraftClient.cpp              \
    ../perkan/CustomRakNetInstance.cpp               \

TARGET_NO_UNDEFINED_LDFLAGS :=

include $(BUILD_SHARED_LIBRARY)
