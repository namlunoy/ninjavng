LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Layers/Jump/GamePlayLayer.cpp \
                   ../../Classes/Layers/Jump/JumpLayer.cpp \
                   ../../Classes/Layers/BanSung/BanSungLayer.cpp \
                   ../../Classes/Layers/Chem/ChemLayer.cpp \
                   ../../Classes/Layers/PhiTieu/PhiTieuHUDLayer.cpp \
                   ../../Classes/Layers/PhiTieu/PhiTieuLayer.cpp \
                   ../../Classes/Layers/TranhNe/TranhNeLayer.cpp \
                   ../../Classes/Models/PhiTieu/Ninja.cpp \
                   ../../Classes/Models/PhiTieu/NinjaModel.cpp \
                   ../../Classes/Models/Jump/Background.cpp \
                   ../../Classes/Models/Jump/Ninja_D.cpp \
                   ../../Classes/Models/Jump/Pillar.cpp \
                   ../../Classes/Models/PhiTieu/Shuriken.cpp \
                   ../../Classes/Scenes/HelloWorldScene.cpp \
                   ../../Classes/Scenes/JumpScene.cpp \
                   ../../Classes/Scenes/BanSungScene.cpp \
                   ../../Classes/Scenes/ChemScene.cpp \
                   ../../Classes/Scenes/PhiTieuScene.cpp \
                   ../../Classes/Scenes/TranhNeScene.cpp \
                   ../../Classes/Utility/Config.cpp \
                   ../../Classes/Utility/XHelper.cpp \
                   ../../Classes/Utility/Tags.cpp \
                   ../../Classes/Utility/Definition.cpp
         

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static


# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
