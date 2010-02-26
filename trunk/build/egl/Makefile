#---------------------------------------------------------------------
# Project configuration.
#---------------------------------------------------------------------
include ../config.inc

# Name of build target.
TARGET := libegl.a

# Source directories (delimited with spaces).
SOURCE_PATH := ../../src/egl

BUILD_INCLUDE := -I../../src/public -I../../src/gl -I../../include

# Source files to build target from.
BUILD_FILES := \
	egl.c \
	config.c \
	display.c \
	surface.c \
	errlog.c \
	context.c
	

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
