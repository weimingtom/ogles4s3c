#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "EGL/egl.h"
#include "errlog.h"
#include "config.h"
#include "surface.h"

typedef struct __surface
{
	EGLConfig	config;

	//attributes
	EGLint		m_VgAlphaFormat;
	EGLint		m_VgColorspace;
	EGLint		m_Width;
	EGLint		m_Height;
	EGLint		m_VerticalResolution;
	EGLint		m_HorizontalResolution;
	EGLBoolean	m_LargestPbuffer;
	EGLBoolean	m_MipmapTexture;
	EGLint		m_MipmapLevel;
	EGLint		m_MultisampleResolve;
	EGLint		m_PixelAspectRation;
	EGLint		m_RenderBuffer;
	EGLint		m_SwapBehavior;
	EGLint		m_TextureFormat;
}SURFACE;

EGLBoolean sfcVerify(EGLSurface surface)
{
	if (EGL_NO_SURFACE == surface
		|| NULL == surface)
	{
		eglRecordError(EGL_BAD_SURFACE);
		return EGL_FALSE;
	}
	return EGL_TRUE;
}

EGLConfig sfcGetConfig(EGLSurface surface)
{
	SURFACE* sfc = (SURFACE*) surface;

	return sfc->config;
}

EGLSurface sfcCreate (EGLConfig config)
{
	SURFACE* sfc;
	
	sfc = (SURFACE*) malloc (sizeof (SURFACE));
	if (NULL == sfc)
	{
		eglRecordError(EGL_BAD_ALLOC);
		return EGL_NO_SURFACE;
	}
	memset (sfc, 0, sizeof(SURFACE));

	sfc->config = cfgCreate();

	if (sfc->config == 0)
	{
		free (sfc);
		return EGL_NO_SURFACE;
	}

	cfgClone(sfc->config, config);

	return (EGLSurface)sfc;
}

EGLBoolean sfcDestroy (EGLSurface surface)
{
	SURFACE* sfc = (SURFACE*) surface;

	if (EGL_FALSE == sfcVerify(surface))
	{
		return EGL_FALSE;
	}

	cfgDestroy(sfc->config);
	free (sfc);
	return EGL_TRUE;
}

EGLBoolean sfcSetAttrib(EGLSurface surface, EGLint attribute, EGLint value)
{
	SURFACE* sfc = (SURFACE*) surface;

	if (EGL_FALSE == sfcVerify(surface))
	{
		return EGL_FALSE;
	}

	switch (attribute)
	{
	case EGL_MIPMAP_LEVEL:
		break;
	case EGL_MULTISAMPLE_RESOLVE:
		break;
	case EGL_SWAP_BEHAVIOR:
		break;
	}

	return EGL_TRUE;
}

EGLBoolean sfcGetAttrib(EGLSurface surface, EGLint attribute, EGLint *value)
{
	SURFACE* sfc = (SURFACE*) surface;

	if (EGL_FALSE == sfcVerify(surface))
	{
		return EGL_FALSE;
	}

	switch (attribute)
	{
		case EGL_VG_ALPHA_FORMAT:
			break;
		case EGL_VG_COLORSPACE:
			break;
		case EGL_CONFIG_ID:
			*value = cfgGetAttrib (sfc->config, EGL_CONFIG_ID);			
			return EGL_TRUE;
		case EGL_HEIGHT:
			break;
		case EGL_WIDTH:
			break;
		case EGL_LARGEST_PBUFFER:
			break;
		case EGL_TEXTURE_FORMAT:
			break;
		case EGL_TEXTURE_TARGET:
			break;
		case EGL_MIPMAP_TEXTURE:
			break;
		case EGL_MIPMAP_LEVEL:
			break;
		case EGL_RENDER_BUFFER:
			break;
		case EGL_HORIZONTAL_RESOLUTION:
			break;
		case EGL_VERTICAL_RESOLUTION:
			break;
		case EGL_PIXEL_ASPECT_RATIO:
			break;
		case EGL_SWAP_BEHAVIOR:
			break;
		case EGL_MULTISAMPLE_RESOLVE:
			break;
	}

	return EGL_TRUE;
}