#include <stdio.h>
#include <stdlib.h>
#include "EGL/egl.h"

int main (int argc, char* argv[])
{
	EGLConfig configs[10];
	EGLint matchingConfigs;
	EGLDisplay dpy;
	EGLSurface glesSurface;
	EGLContext glesContext;
	EGLint major, minor;
	const EGLint configAttribs[] = {
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, EGL_DONT_CARE,
		EGL_DEPTH_SIZE, 16,
		EGL_STENCIL_SIZE, EGL_DONT_CARE,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_NONE, EGL_NONE
	};

	dpy = eglGetDisplay(0);

	if (!eglInitialize(dpy, &major, &minor))
	{
		printf ("eglInitialize failed.\n");
		return EGL_FALSE;
	}

	if (!eglChooseConfig(dpy, configAttribs, &configs[0], 10, &matchingConfigs))
	{
		printf ("eglChooseConfig failed.\n");
		return EGL_FALSE;
	}

	if (matchingConfigs < 1)
	{
		printf ("matchingConfigs < 1.\n");
		return EGL_FALSE;
	}

	glesSurface = eglCreateWindowSurface(dpy, configs[0], 0, configAttribs);
	if (!glesSurface)
	{
		printf ("eglCreateWindowSurface failed.\n");
		return EGL_FALSE;
	}

	glesContext = eglCreateContext(dpy, configs[0], 0, configAttribs);
	if (!glesContext)
	{
		printf ("eglCreateContext failed.\n");
		return EGL_FALSE;
	}

	eglMakeCurrent(dpy, glesSurface, glesSurface, glesContext);
	



	sleep (5);

	eglMakeCurrent (dpy, NULL, NULL, NULL);
	if (glesContext)
	{
		eglDestroyContext(dpy, glesContext);
	}

	if (glesSurface)
		eglDestroySurface (dpy, glesSurface);

	eglTerminate(dpy);
	return EGL_TRUE;
}
