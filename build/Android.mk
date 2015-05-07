LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

define walk    
    $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))    
endef 

ALLFILES := $(call walk, $(LOCAL_PATH)/../../Classes)  
FILE_LIST := $(filter %.cpp %.c, $(ALLFILES)) 


LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

# REPLACE FOLDER_NAME WITH YOUR SUBFOLDER
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
# LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/FOLDER_NAME

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)