include config.inc

export SHADER_PATH=../src/tests

SUBDIRS := gl egl utils tests

all:
	$(MAKE) -C gl all
	$(MAKE) -C egl all
	$(MAKE) -C utils all
	$(MAKE) -C example all
#	$(MAKE) -C tests all

clean:
	$(MAKE) -C gl clean
	$(MAKE) -C egl clean
	$(MAKE) -C utils clean
	$(MAKE) -C example clean
#	$(MAKE) -C tests clean

debug:	all
	gdb -d ../src/gl -d ../src/egl -d ../src/utils -d ../src/tests tests/$(PLATFORM)-$(BUILD_CONFIG)/tests
