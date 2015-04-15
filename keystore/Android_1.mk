LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

#REPLACE FOLDER_NAME WITH YOUR SUBFOLDER, AND MODIFY THE EXTENSION TO ADD ANY OTHER EXTENSIONS
FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp) 
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/*/*.cpp) 
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/*/*/*.cpp) 

LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

# REPLACE FOLDER_NAME WITH YOUR SUBFOLDER
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
# LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/FOLDER_NAME

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)