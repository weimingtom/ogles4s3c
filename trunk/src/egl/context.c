#include <stdlib.h>
#include <string.h>

#include "EGL/egl.h"
#include "errlog.h"
#include "surface.h"

typedef struct _context
{
	EGLBoolean m_current;
    EGLConfig config;

	EGLSurface m_ReadSurface;
	EGLSurface m_DrawSurface;
}CONTEXT;

static CONTEXT* g_CurrentContext = EGL_NO_CONTEXT;

EGLBoolean ctxVerify (EGLContext context)
{
	if (EGL_NO_CONTEXT == context
		|| NULL == context)
	{
		eglRecordError(EGL_BAD_CONTEXT);
		return EGL_FALSE;
	}
	return EGL_TRUE;
}

EGLContext ctxCreate (EGLConfig config)
{
	CONTEXT* ctx;

	ctx = (CONTEXT*) malloc (sizeof (CONTEXT));
	if (NULL == ctx)
	{
		eglRecordError(EGL_BAD_ALLOC);
		return EGL_NO_CONTEXT;
	}

	memset (ctx, 0, sizeof (CONTEXT));
	ctx->config = config;

	return (EGLContext)ctx;
}

EGLBoolean ctxDestroy (EGLContext context)
{
	CONTEXT* ctx = (CONTEXT*) context;

	if (EGL_FALSE == ctxVerify(context))
	{
		return EGL_FALSE;
	}

	free (ctx);
	return EGL_TRUE;
}

EGLBoolean ctxSetCurrent(EGLContext context)
{
	CONTEXT* ctx = (CONTEXT*) context;

	if (EGL_FALSE == ctxVerify(context))
	{
		return EGL_FALSE;
	}

	if (EGL_TRUE == ctxVerify((EGLContext)g_CurrentContext))
	{
		g_CurrentContext->m_current = EGL_FALSE;
	}

	ctx->m_current = EGL_TRUE;
	g_CurrentContext = ctx;
	
	return EGL_TRUE;
}

EGLContext ctxGetCurrent()
{
	return (EGLContext)g_CurrentContext;
}

EGLBoolean ctxSetReadSurface (EGLContext context, EGLSurface surface)
{
	CONTEXT* ctx = (CONTEXT*) context;

	if (EGL_FALSE == ctxVerify(context))
	{
		return EGL_FALSE;
	}

	ctx->m_ReadSurface = surface;

	return EGL_TRUE;
}

EGLBoolean ctxSetDrawSurface (EGLContext context, EGLSurface surface)
{
	CONTEXT* ctx = (CONTEXT*) context;

	if (EGL_FALSE == ctxVerify(context))
	{
		return EGL_FALSE;
	}

	ctx->m_DrawSurface = surface;

	return EGL_TRUE;
}

EGLSurface ctxGetSurface (EGLContext context, EGLint readdraw)
{
	CONTEXT* ctx = (CONTEXT*) context;

	if (EGL_FALSE == ctxVerify(context))
	{
		return EGL_NO_SURFACE;
	}

	switch (readdraw)
	{
	case EGL_DRAW:
		return ctx->m_DrawSurface;
	case EGL_READ:
		return ctx->m_ReadSurface;
	default:
		eglRecordError(EGL_BAD_PARAMETER);
		return EGL_NO_SURFACE;
	}

	return EGL_NO_SURFACE;
}

EGLConfig ctxGetConfig(EGLContext context)
{
	CONTEXT* ctx = (CONTEXT*) context;
	if (EGL_FALSE == ctxVerify(context))
	{
		return NULL;
	}

	return ctx->config;
}
