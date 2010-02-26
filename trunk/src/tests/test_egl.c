#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <CUnit/CUnit.h>

#include "EGL/egl.h"

static EGLDisplay Display;
void tstGetDisplay1(void)
{
	EGLDisplay display;

	display = eglGetDisplay(0);
	CU_ASSERT_EQUAL(EGL_SUCCESS, eglGetError());	
	Display = display;

}

void tstInitialize()
{
	EGLBoolean ret;
	EGLint major, minor;
	EGLDisplay display;
	display = eglGetDisplay(0);

	CU_ASSERT_EQUAL(display, Display);
	ret = eglInitialize(display, &major, &minor);
	
	CU_ASSERT_EQUAL(ret, EGL_TRUE);
	CU_ASSERT_EQUAL(major, 1);
	CU_ASSERT_EQUAL(minor, 4);

	eglTerminate(display);
}
	
void tstQueryString1()
{
	EGLBoolean ret;
	EGLint major, minor;
	EGLDisplay display;
	char* res;
	display = eglGetDisplay(0);

	CU_ASSERT_EQUAL(display, Display);
	ret = eglInitialize(display, &major, &minor);
	CU_ASSERT_EQUAL(ret, EGL_TRUE);

	res = eglQueryString (display, EGL_CLIENT_APIS);

	CU_ASSERT_STRING_EQUAL(res, "OpenGL_ES");

	eglTerminate(display);
}

void tstQueryString2()
{
	EGLBoolean ret;
	EGLint major, minor;
	EGLDisplay display;
	char* res;
	display = eglGetDisplay(0);

	CU_ASSERT_EQUAL(display, Display);
	ret = eglInitialize(display, &major, &minor);
	CU_ASSERT_EQUAL(ret, EGL_TRUE);

	res = eglQueryString (display, EGL_VENDOR);

	CU_ASSERT_STRING_EQUAL(res, "CPSOFT");

	eglTerminate(display);
}

void tstQueryString3()
{
	EGLBoolean ret;
	EGLint major, minor;
	EGLDisplay display;
	char* res;
	display = eglGetDisplay(0);

	CU_ASSERT_EQUAL(display, Display);
	ret = eglInitialize(display, &major, &minor);
	CU_ASSERT_EQUAL(ret, EGL_TRUE);

	res = eglQueryString (display, EGL_VERSION);

	CU_ASSERT_STRING_EQUAL(res, "1.4 hardware");

	eglTerminate(display);
}

void tstQueryString4()
{
	EGLBoolean ret;
	EGLint major, minor;
	EGLDisplay display;
	char* res;
	display = eglGetDisplay(0);

	CU_ASSERT_EQUAL(display, Display);
	ret = eglInitialize(display, &major, &minor);
	CU_ASSERT_EQUAL(ret, EGL_TRUE);

	res = eglQueryString (display, EGL_EXTENSIONS);

	CU_ASSERT_STRING_EQUAL(res, "");

	eglTerminate(display);
}

void tstQueryString5()
{
	EGLBoolean ret;
	EGLint major, minor;
	EGLDisplay display;
	char* res;
	display = eglGetDisplay(0);

	CU_ASSERT_EQUAL(display, Display);
	ret = eglInitialize(display, &major, &minor);
	CU_ASSERT_EQUAL(ret, EGL_TRUE);

	res = eglQueryString (display, 100);

	CU_ASSERT_EQUAL(res, NULL);
	CU_ASSERT_EQUAL(EGL_BAD_PARAMETER, eglGetError());	

	eglTerminate(display);
}

void tstQueryString6()
{
	EGLBoolean ret;
	char* res;
	
	res = eglQueryString (1231, 100);
	CU_ASSERT_EQUAL(res, NULL);
	CU_ASSERT_EQUAL(EGL_BAD_DISPLAY, eglGetError());	

}

static CU_TestInfo egl_GetDisplay[] = {
	{"eglGetDisplay 1", tstGetDisplay1},
	CU_TEST_INFO_NULL,
};

static CU_TestInfo egl_Initialize[] = {
	{"eglInitialize 1", tstInitialize},
	CU_TEST_INFO_NULL,
};

static CU_TestInfo egl_QueryString[] = {
	{"eglQueryString 1", tstQueryString1},
	{"eglQueryString 2", tstQueryString2},
	{"eglQueryString 3", tstQueryString3},
	{"eglQueryString 4", tstQueryString4},
	{"eglQueryString 5", tstQueryString5},
	{"eglQueryString 6", tstQueryString6},
	CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
	{ "EGL GetDisplay", NULL, NULL, egl_GetDisplay },
	{ "EGL Initialize", NULL, NULL, egl_Initialize },
	{ "EGL QueryString", NULL, NULL, egl_QueryString },
	CU_SUITE_INFO_NULL,
};

void AddEglTests(void)
{
	assert (NULL != CU_get_registry());
	assert (!CU_is_test_running());

	if (CU_register_suites(suites) != CUE_SUCCESS)
	{
		fprintf (stderr, "suite registration failed - %s\n",
			CU_get_error_msg());
		exit(EXIT_FAILURE);
	}
}

