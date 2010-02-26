#ifndef __CONTEXT_H__
#define __CONTEXT_H__

EGLBoolean ctxVerify (EGLContext context);
EGLContext ctxCreate (EGLConfig config);
EGLBoolean ctxDestroy (EGLContext context);
EGLBoolean ctxSetReadSurface (EGLContext context, EGLSurface surface);
EGLBoolean ctxSetDrawSurface (EGLContext context, EGLSurface surface);
EGLBoolean ctxSetCurrent(EGLContext context);
EGLContext ctxGetCurrent();
EGLSurface ctxGetSurface (EGLContext context, EGLint readdraw);
EGLConfig ctxGetConfig(EGLContext context);
#endif