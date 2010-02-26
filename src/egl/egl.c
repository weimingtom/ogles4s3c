#include <stdlib.h>
#include "KHR/khrplatform.h"
#include "EGL/eglplatform.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"
#include "zgles.h"
#include "config.h"
#include "display.h"
#include "surface.h"
#include "context.h"
#include "errlog.h"

EGLAPI EGLDisplay EGLAPIENTRY eglGetDisplay(EGLNativeDisplayType display_id)
{
	eglRecordError(EGL_SUCCESS);
	return dpyGetDisplay ();
}

EGLAPI EGLBoolean EGLAPIENTRY eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor)
{
	eglRecordError(EGL_SUCCESS);

	if (EGL_TRUE != dpyVerify(dpy))
	{
		return EGL_FALSE;
	}

	if (NULL == major && NULL == minor)
	{
		return EGL_FALSE;
	}

	if (NULL != major)
	{
		*major = EGL_VERSION_MAJOR;
	}

	if (NULL != minor)
	{
		*minor = EGL_VERSION_MINOR;
	}

	if (EGL_TRUE != dpyInitialize(dpy))
	{
		return EGL_FALSE;
	}
	
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglTerminate(EGLDisplay dpy)
{
	eglRecordError(EGL_SUCCESS);
	return dpyTerminate(dpy);
}

EGLAPI const char * EGLAPIENTRY eglQueryString(EGLDisplay dpy, EGLint name)
{
	eglRecordError(EGL_SUCCESS);
	if (EGL_TRUE != is_Initialized(dpy))
	{
		return EGL_FALSE;
	}

	eglRecordError(EGL_SUCCESS);

	switch (name)
	{
	case EGL_CLIENT_APIS:
		return EGL_CLIENT_STRING;

	case EGL_VENDOR:
		return EGL_CONFIG_VENDOR;

	case EGL_VERSION:
		return EGL_VERSION_NUMBER;

	case EGL_EXTENSIONS:
		return "";

	default:
		eglRecordError(EGL_BAD_PARAMETER);
		return NULL;
	}

	return NULL;
}

// config functions
EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigs(EGLDisplay dpy, EGLConfig *configs,
			 EGLint config_size, EGLint *num_config)
{
	eglRecordError(EGL_SUCCESS);
	return GetConfigs(configs, config_size, num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglChooseConfig(EGLDisplay dpy, const EGLint *attrib_list,
			   EGLConfig *configs, EGLint config_size,
			   EGLint *num_config)
{
	eglRecordError(EGL_SUCCESS);
	return ChooseConfig(attrib_list, configs, config_size, num_config);
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigAttrib(EGLDisplay dpy, EGLConfig config,
			      EGLint attribute, EGLint *value)
{
	eglRecordError(EGL_SUCCESS);
	*value = cfgGetAttrib(config, attribute);
	if (EGL_NONE == *value)
	{
		eglRecordError(EGL_BAD_ATTRIBUTE);
		return EGL_FALSE;
	}
	return EGL_TRUE;
}



EGLAPI EGLSurface EGLAPIENTRY eglCreateWindowSurface(EGLDisplay dpy, EGLConfig config,
				  EGLNativeWindowType win,
				  const EGLint *attrib_list)
{	
	eglRecordError(EGL_SUCCESS);
	return dpyGetSurface(dpy);	
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferSurface(EGLDisplay dpy, EGLConfig config,
				   const EGLint *attrib_list)
{
	EGLSurface surface;
	eglRecordError(EGL_SUCCESS);
	surface = sfcCreate (config);
	return surface;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePixmapSurface(EGLDisplay dpy, EGLConfig config,
				  EGLNativePixmapType pixmap,
				  const EGLint *attrib_list)
{
	EGLSurface surface;
	eglRecordError(EGL_SUCCESS);
	surface = sfcCreate (config);
	return surface;
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
	eglRecordError(EGL_SUCCESS);
	return sfcDestroy (surface);
}

EGLAPI EGLBoolean EGLAPIENTRY eglSurfaceAttrib(EGLDisplay dpy, EGLSurface surface,
			    EGLint attribute, EGLint value)
{
	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglQuerySurface(EGLDisplay dpy, EGLSurface surface,
			   EGLint attribute, EGLint *value)
{
	eglRecordError(EGL_SUCCESS);
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglBindAPI(EGLenum api)
{
	return EGL_FALSE;
}

EGLAPI EGLenum EGLAPIENTRY eglQueryAPI(void)
{
	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitClient(void)
{
	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseThread(void)
{
	return EGL_FALSE;
}

//todo
EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferFromClientBuffer(
	      EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer,
	      EGLConfig config, const EGLint *attrib_list)
{
	EGLSurface surface;
	eglRecordError(EGL_SUCCESS);
	surface = sfcCreate (config);
	return surface;
}



EGLAPI EGLBoolean EGLAPIENTRY eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	return EGL_FALSE;
}


EGLAPI EGLBoolean EGLAPIENTRY eglSwapInterval(EGLDisplay dpy, EGLint interval);


EGLAPI EGLContext EGLAPIENTRY eglCreateContext(EGLDisplay dpy, EGLConfig config,
			    EGLContext share_context,
			    const EGLint *attrib_list)
{
	EGLContext context;
	eglRecordError(EGL_SUCCESS);
	context = ctxCreate (config);
	return context;
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
	eglRecordError(EGL_SUCCESS);
	return ctxDestroy(ctx);
}

EGLAPI EGLBoolean EGLAPIENTRY eglMakeCurrent(EGLDisplay dpy, EGLSurface draw,
			  EGLSurface read, EGLContext ctx)
{
	eglRecordError(EGL_SUCCESS);
	if (EGL_FALSE == ctxSetCurrent(ctx)
		|| EGL_FALSE == ctxSetReadSurface (ctx, read)
		|| EGL_FALSE == ctxSetDrawSurface (ctx, draw))
	{
		return EGL_FALSE;
	}
	return EGL_TRUE;
}

EGLAPI EGLContext EGLAPIENTRY eglGetCurrentContext(void)
{
	eglRecordError(EGL_SUCCESS);
	return ctxGetCurrent();
}

EGLAPI EGLSurface EGLAPIENTRY eglGetCurrentSurface(EGLint readdraw)
{
	eglRecordError(EGL_SUCCESS);
	return ctxGetSurface(ctxGetCurrent(), readdraw);
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetCurrentDisplay(void)
{
	eglRecordError(EGL_SUCCESS);
	return dpyGetCurrentDisplay();
}

EGLAPI EGLBoolean EGLAPIENTRY eglQueryContext(EGLDisplay dpy, EGLContext ctx,
			   EGLint attribute, EGLint *value)
{
	EGLConfig config;
	eglRecordError(EGL_SUCCESS);

	config = ctxGetConfig(ctx);
	if (config == 0)
	{
		return EGL_FALSE;
	}
	*value = cfgGetAttrib(config, attribute);

	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitGL(void)
{
	EGLenum api = eglQueryAPI();
	eglBindAPI(EGL_OPENGL_ES_API);
	eglWaitClient();
	eglBindAPI(api);

	return EGL_TRUE;
}

//todo
EGLAPI EGLBoolean EGLAPIENTRY eglWaitNative(EGLint engine)
{
	return EGL_FALSE;
}

//todo
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
	return EGL_FALSE;
}

//todo
EGLAPI EGLBoolean EGLAPIENTRY eglCopyBuffers(EGLDisplay dpy, EGLSurface surface,
			  EGLNativePixmapType target)
{
	return EGL_FALSE;
}

/* Now, define eglGetProcAddress using the generic function ptr. type */
EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY
       eglGetProcAddress(const char *procname);