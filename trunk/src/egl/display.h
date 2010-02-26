#ifndef __DISPLAY_H__
#define __DISPLAY_H__

EGLBoolean dpyVerify(EGLDisplay dpy);
EGLDisplay dpyGetDisplay();
EGLBoolean dpyInitialize(EGLDisplay dpy);
EGLBoolean dpyTerminate(EGLDisplay dpy);

EGLBoolean is_Initialized(EGLDisplay dpy);
EGLDisplay dpyGetCurrentDisplay();
#endif
