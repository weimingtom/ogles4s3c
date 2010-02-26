#---------------------------------------------------------------------
# Project configuration.
#---------------------------------------------------------------------
include ../config.inc

# Name of build target.
TARGET := libutils.a

# Source directories (delimited with spaces).
SOURCE_PATH := ../../src/utils

SDL_INCLUDE := -I/sw/include/SDL
BUILD_INCLUDE := -I../../src/public $(SDL_INCLUDE)
	
# Source files to build target from.
BUILD_FILES := \

# Build type [lib] or [bin]
BUILD_TYPE := lib

#---------------------------------------------------------------------
# Configure build enviroment.
#---------------------------------------------------------------------

include ../../makefiles/$(PLATFORM).inc
include ../../makefiles/Makefile.gcc

#---------------------------------------------------------------------
# The End.
#---------------------------------------------------------------------
