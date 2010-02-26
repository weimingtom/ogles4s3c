#ifndef __SURFACE_H__
#define __SURFACE_H__

EGLBoolean sfcVerify(EGLSurface surface);
EGLSurface sfcCreate (EGLConfig config);
EGLBoolean sfcDestroy (EGLSurface surface);
EGLConfig sfcGetConfig(EGLSurface surface);
#endif