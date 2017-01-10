LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := com.perkan.addon
LOCAL_LDLIBS    := -L$(LOCAL_PATH) -lminecraftpe -lmcpelauncher_tinysubstrate                      \
                   -lmcpelauncher_new -lm -lc -lz -ldl -llog -lstdc++                              \

LOCAL_SRC_FILES :=                                   \
    main.cpp                                         \
    vars.cpp                                         \
    NewModPE.cpp                                     \
    ../perkan/Hooker.cpp                             \
    ../perkan/CustomMinecraftClient.cpp              \
    ../perkan/CustomRakNetInstance.cpp               \
    ../perkan/CustomMob.cpp                          \
    ../header/level/Level.cpp                        \
    ../header/client/MinecraftPackets.cpp            \
    ../header/network/sender/BatchedPacketSender.cpp \
    ../header/entity/player/Player.cpp               \

TARGET_NO_UNDEFINED_LDFLAGS :=

include $(BUILD_SHARED_LIBRARY)
