#---------------------------------------------------------------------
# Project configuration.
#---------------------------------------------------------------------
include ../config.inc

# Name of build target.
TARGET := tests

# Build type [lib] or [bin]
BUILD_TYPE := bin

BUILD_DIR := $(PLATFORM)-$(BUILD_CONFIG)

# Source directories (delimited with spaces).
SOURCE_PATH := ../../src/tests

BUILD_INCLUDE += -I../../include -I../../src/public -I../../src/utils
BUILD_LIBPATH += 

# Source files to build target from.
BUILD_FILES := \
	tests.c \
	test_egl.c

PROJECT_LIBS := \
	../gl/$(BUILD_DIR)/libgl.a 		\
	../egl/$(BUILD_DIR)/libegl.a 	\
	../utils/$(BUILD_DIR)/libutils.a 
	
# Libraries to link
BUILD_LIBS += 

# Other linker flags
BUILD_LFLAGS += -lcunit


#---------------------------------------------------------------------
# Configure build enviroment.
#---------------------------------------------------------------------

include ../../makefiles/$(PLATFORM).inc
include ../../makefiles/Makefile.gcc

#---------------------------------------------------------------------
# The End.
#---------------------------------------------------------------------
