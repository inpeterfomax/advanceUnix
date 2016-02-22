LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= clientudp.c 
LOCAL_MODULE := clientudp
LOCAL_MODULE_TAGS := eng
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS) 
LOCAL_SRC_FILES:= serverudp.c 
LOCAL_MODULE :=  serverudp
LOCAL_MODULE_TAGS := eng
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS) 
LOCAL_SRC_FILES:= servertcp.c
LOCAL_MODULE :=  servertcp
LOCAL_MODULE_TAGS := eng
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS) 
LOCAL_SRC_FILES:= clienttcp.c
LOCAL_MODULE :=  clienttcp
LOCAL_MODULE_TAGS := eng
include $(BUILD_EXECUTABLE)

