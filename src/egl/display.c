#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <error.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/fb.h>
#include <unistd.h>
#include <string.h>
#include "EGL/egl.h"
#include "errlog.h"
#include "config.h"
#include "surface.h"
#include "display.h"



typedef struct fbdev{
	int fb;
	unsigned long fb_mem_offset;
	unsigned long fb_mem;
	struct fb_fix_screeninfo fb_fix;
	struct fb_var_screeninfo fb_var;
	char dev[20];
}FBDEV, *PFBDEV;

typedef struct _display
{
	int initialized;
	FBDEV	fbdev;
	EGLSurface surface;
}DISPLAY;


static DISPLAY* g_pDisplay = NULL;

EGLBoolean dpyVerify(EGLDisplay dpy)
{
	if (g_pDisplay == NULL || g_pDisplay != ((DISPLAY*)dpy))
	{
		eglRecordError(EGL_BAD_DISPLAY);
		return EGL_FALSE;
	}
	return EGL_TRUE;
}

EGLBoolean is_Initialized(EGLDisplay dpy)
{
	DISPLAY* display = (DISPLAY*) dpy;
	
	if (EGL_TRUE != dpyVerify(dpy))
	{
		return EGL_FALSE;
	}

	if (EGL_FALSE == display->initialized)
	{
		eglRecordError(EGL_NOT_INITIALIZED);
	}

	return display->initialized;
}

EGLBoolean dpyAddDefaultConfig(EGLDisplay dpy)
{
	DISPLAY* display = (DISPLAY*) dpy;
	PFBDEV pFbdev;
	
	if (EGL_TRUE != dpyVerify(dpy))
	{
		return EGL_FALSE;
	}
	pFbdev = &display->fbdev;

	return cfgAddDefaultConfig(pFbdev->fb_var.bits_per_pixel,			//BufferSize
						pFbdev->fb_var.red.length,				//RedSize
						pFbdev->fb_var.green.length,			//GreenSize
						pFbdev->fb_var.blue.length,				//BlueSize
						0,										//LuminanceSize
						pFbdev->fb_var.transp.length,			//AlphaSize
						0,										//AlphaMaskSize
						0,										//BindToTextureRGB
						0,										//BindToTextureRGBA
						0,										//ColorBufferType
						EGL_SLOW_CONFIG,						//ConfigCaveat
						0,										//Conformat
						16,										//DepthSize
						0,										//Level
						1024,									//MaxPBufferWidth
						1024,									//MaxPBufferHeight
						1024 * 1024,							//MaxPBufferPixels
						0,										//MaxSwapInterval
						0,										//MinSwapInterval
						EGL_FALSE,								//NativeRenderable
						0,										//NativeVisualID
						EGL_NONE,								//NativeVisualType
						0,										//RenderableType
						0,										//SampleBuffers
						0,										//Samples
						32,										//StencilSize
						EGL_PBUFFER_BIT | EGL_WINDOW_BIT,		//SurfaceType
						EGL_NONE,								//TransparentType
						0,										//TransparentRedValue
						0,										//TransparentGreenValue
						0,										//TransparentBlueValue,
						pFbdev->fb_var.xres,					//Width
						pFbdev->fb_var.yres);					//Height
}


static EGLBoolean fb_open(PFBDEV pFbdev)
{
	pFbdev->fb = open(pFbdev->dev, O_RDWR);
	if (pFbdev->fb < 0)
	{
		printf ("Error opening %s: %m. Check kernel config.\n", pFbdev->dev);
		return EGL_FALSE;
	}

	if (-1 == ioctl (pFbdev->fb, FBIOGET_VSCREENINFO, &(pFbdev->fb_var)))
	{
		printf ("ioctl FBIOGET_VSCREENINFO.\n");
		return EGL_FALSE;
	}

	if (-1 == ioctl (pFbdev->fb, FBIOGET_FSCREENINFO, &(pFbdev->fb_fix)))
	{
		printf ("ioctl FBIOGET_FSCREENINFO.\n");
		return EGL_FALSE;
	}

	//pFbdev->fb_mem_offset = (unsigned long) (pFbdev->fb_fix.smem_start);
	pFbdev->fb_mem = (unsigned long int)mmap(NULL, pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset,
			PROT_READ | PROT_WRITE, MAP_SHARED, pFbdev->fb, 0);
	if (-1L == (long)pFbdev->fb_mem)
	{
		printf ("mmap error! mem: %d offset: %d\n", pFbdev->fb_mem, pFbdev->fb_mem_offset);
		return EGL_FALSE;
	}

	memset (pFbdev->fb_mem, 0xff, pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset);

	return EGL_TRUE;
}

static EGLBoolean fb_close (PFBDEV pFbdev)
{
	close (pFbdev->fb);
	pFbdev->fb = -1;
	return EGL_TRUE;
}


EGLDisplay dpyGetDisplay()
{
	if (g_pDisplay == NULL)
	{
		g_pDisplay = (DISPLAY*)malloc(sizeof(DISPLAY));
		memset (g_pDisplay, 0, sizeof(DISPLAY));
	}
	cfgInitManagement();
	return (EGLDisplay) g_pDisplay;
}

EGLBoolean dpyInitialize(EGLDisplay dpy)
{
	DISPLAY* display = (DISPLAY*) dpy;
	EGLBoolean ret;

	if (EGL_TRUE == is_Initialized(dpy))
	{
		return EGL_TRUE;
	}

	eglRecordError(EGL_NOT_INITIALIZED);
	strcpy(display->fbdev.dev, "/dev/fb0");

	ret = fb_open (&display->fbdev);
	if (EGL_TRUE != ret)
	{
		dpyTerminate (dpy);
		return EGL_FALSE;
	}

	if (EGL_TRUE != dpyAddDefaultConfig (dpy))
	{
		dpyTerminate (dpy);
		return EGL_FALSE;
	}

	display->surface = sfcCreate(cfgGet(0));

	if (EGL_FALSE == sfcVerify(display->surface))
	{
		dpyTerminate(dpy);
		return EGL_FALSE;
	}
	
	display->initialized = EGL_TRUE;

	return EGL_TRUE;
}

EGLBoolean dpyTerminate(EGLDisplay dpy)
{
	DISPLAY* display = (DISPLAY*) dpy;
	
	if (dpyVerify(dpy))
	{
		return EGL_FALSE;
	}

	if (EGL_TRUE == is_Initialized(dpy))
	{
		fb_close(&(display->fbdev));
	}

	if (EGL_TRUE == sfcVerify(display->surface))
	{
		sfcDestroy (display->surface);
	}

	if (display == g_pDisplay)
	{
		g_pDisplay = NULL;
	}
	
	free (display);
	return EGL_TRUE;
}

EGLSurface dpyGetSurface (EGLDisplay dpy)
{
	DISPLAY* display = (DISPLAY*) dpy;
	if (EGL_FALSE == is_Initialized(dpy))
	{
		return NULL;
	}

	return display->surface;
}

EGLDisplay dpyGetCurrentDisplay()
{
	return (EGLDisplay)g_pDisplay;
}



