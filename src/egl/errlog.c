#include "EGL/egl.h"
#include "error.h"

static EGLint g_error = EGL_SUCCESS;

void eglRecordError(EGLint error)
{
	g_error = error;
	return;
}

EGLAPI EGLint EGLAPIENTRY eglGetError(void)
{
	return g_error;
}