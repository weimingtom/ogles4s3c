#---------------------------------------------------------------------
# Project configuration.
#---------------------------------------------------------------------

include ../config.inc

# Name of build target.
TARGET := libgl.a

# Source directories (delimited with spaces).
SOURCE_PATH := ../../src/gl

BUILD_INCLUDE := -I../../include -I../../src/public

# Source files to build target from.
BUILD_FILES := \
	gl.c


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
