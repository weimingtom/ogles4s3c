#include "EGL/egl.h"
#include "config.h"


typedef struct _config_management
{
	CONFIG s_AllConfigurations[]={
			16,				//	EGLint	bufferSize,
		    5,				//	EGLint	redSize,
		    6,				//	EGLint	greenSize,
		    5,				//	EGLint	blueSize,
		    8,				//	EGLint	alphaSize,
		    EGL_SLOW_CONFIG,//	EGLint	configCaveat,
		    1,				//	EGLint	configID,
		    16,				//	EGLint	depthSize,
		    0,				//	EGLint	level,
		    1024,			//	EGLint	maxPBufferWidth,
		    1024,			//	EGLint	maxPBufferHeight,
		    1024 * 1024,	//	EGLint	mxPBufferPixels,
		    EGL_FALSE,		//	EGLint	nativeRenderable,
		    0,				//	EGLint	nativeVisualID,
		    EGL_NONE,		//	EGLint	nativeVisualType,
		    0,				//	EGLint	sampleBuffers,
		    0,				//	EGLint	samples,
		    32,				//	EGLint	stencilSize,
		    EGL_PBUFFER_BIT | EGL_WINDOW_BIT,//	EGLint	surfaceType,
		    EGL_NONE,		//	EGLint	transparentType,
		    0,				//	EGLint	transparentRedValue,
		    0,				//	EGLint	transparentGreenValue,
		    0,				//	EGLint	transparentBlueValue,
		    480,			//  EGLint	width,
		    272				//  EGLint	height
	};
	const EGLint s_NumConfigurations;
}CONFIG_MANAGEMENT;

static CONFIG_MANAGEMENT cfg_management;

EGLBoolean GetConfigs(EGLConfig * result, EGLint configSize, EGLint * numConfig)
{
	int index = 0;
	if (result == 0)
	{
		// special case: inquire number of configurations available
		*numConfig = cfg_managemnt.s_NumConfigurations;
		return EGL_TRUE;
	}

	if (configSize > cfg_managemnt.s_NumConfigurations)
	{
		configSize = cfg_managemnt.s_NumConfigurations;
	}

	//fixme
	for (index = 0; index < configSize; ++index)
	{
		result[index] = &s_AllConfigurations[index];
	}

	*numConfig = configSize;
	return EGL_TRUE;
}

EGLBoolean ChooseConfig(const EGLint * attribList, EGLConfig * result, EGLint configSize, EGLint * numConfig)
{
	// for now, as we only have one configuration available, just return that.
	// to be a correct implementation, we will have at least to verify that
	// the attributes specified match that.
	return GetConfigs(result, configSize, numConfig);
}

EGLint GetConfigAttrib(EGLDisplay dpy, CONFIG* config, EGLint attribute)
{
	switch (attribute)
	{
	case EGL_BUFFER_SIZE:
		return config->m_BufferSize;

	case EGL_ALPHA_SIZE:
		return config->m_AlphaSize;

	case EGL_BLUE_SIZE:
		return config->m_BlueSize;

	case EGL_GREEN_SIZE:
		return config->m_GreenSize;

	case EGL_RED_SIZE:
		return config->m_RedSize;

	case EGL_LUMINANCE_SIZE:
		return config->m_LuminanceSize;

	case EGL_ALPHA_MASK_SIZE:
		return config->m_AlphaMaskSize;

	case EGL_BIND_TO_TEXTURE_RGB:
		return config->m_BindToTextureRGB;

	case EGL_BIND_TO_TEXTURE_RGBA:
		return config->m_BindToTextureRGBA;

	case EGL_COLOR_BUFFER_TYPE:
		return config->m_ColorBufferType;

	case EGL_RENDERABLE_TYPE:
		return config->m_RenderableType;
	
	case EGL_CONFORMANT:
		return config->m_Conformat;

	case EGL_MAX_SWAP_INTERVAL:
		return config->m_MaxSwapInterval;

	case EGL_MIN_SWAP_INTERVAL:
		return config->m_MinSwapInterval;

	case EGL_STENCIL_SIZE:
		return config->m_StencilSize;

	case EGL_DEPTH_SIZE:
		return config->m_DepthSize;

	case EGL_CONFIG_CAVEAT:
		return config->m_ConfigCaveat;

	case EGL_CONFIG_ID:
		return config->m_ConfigID;

	case EGL_LEVEL:
		return config->m_Level;

	case EGL_MAX_PBUFFER_HEIGHT:
		return config->m_MaxPBufferHeight;

	case EGL_MAX_PBUFFER_PIXELS:
		return config->m_MaxPBufferPixels;

	case EGL_MAX_PBUFFER_WIDTH:
		return config->m_MaxPBufferWidth;

	case EGL_NATIVE_RENDERABLE:
		return config->m_NativeRenderable;

	case EGL_NATIVE_VISUAL_ID:
		return config->m_NativeVisualID;

	case EGL_NATIVE_VISUAL_TYPE:
		return config->m_NativeVisualType;

	case EGL_SAMPLES:
		return config->m_Samples;

	case EGL_SAMPLE_BUFFERS:
		return config->m_SampleBuffers;

	case EGL_SURFACE_TYPE:
		return config->m_SurfaceType;

	case EGL_TRANSPARENT_TYPE:
		return config->m_TransparentType;

	case EGL_TRANSPARENT_BLUE_VALUE:
		return config->m_TransparentBlueValue;

	case EGL_TRANSPARENT_GREEN_VALUE:
		return config->m_TransparentGreenValue;

	case EGL_TRANSPARENT_RED_VALUE:
		return config->m_TransparentRedValue;

	case EGL_WIDTH:
		return config->m_Width;

	case EGL_HEIGHT:
		return config->m_Height;

	default:
		return EGL_NONE;
	}

	return EGL_NONE;
}

EGLint SetConfigAttrib(EGLDisplay dpy, CONFIG* config, EGLint attribute, EGLint value)
{
	switch (attribute)
	{
	case EGL_BUFFER_SIZE:
		return config->m_BufferSize = value;

	case EGL_ALPHA_SIZE:
		return config->m_AlphaSize = value;

	case EGL_BLUE_SIZE:
		return config->m_BlueSize = value;

	case EGL_GREEN_SIZE:
		return config->m_GreenSize = value;

	case EGL_RED_SIZE:
		return config->m_RedSize = value;

	case EGL_LUMINANCE_SIZE:
		return config->m_LuminanceSize = value;

	case EGL_ALPHA_MASK_SIZE:
		return config->m_AlphaMaskSize = value;

	case EGL_BIND_TO_TEXTURE_RGB:
		return config->m_BindToTextureRGB = value;

	case EGL_BIND_TO_TEXTURE_RGBA:
		return config->m_BindToTextureRGBA = value;

	case EGL_COLOR_BUFFER_TYPE:
		return config->m_ColorBufferType = value;

	case EGL_RENDERABLE_TYPE:
		return config->m_RenderableType = value;
	
	case EGL_CONFORMANT:
		return config->m_Conformat = value;

	case EGL_MAX_SWAP_INTERVAL:
		return config->m_MaxSwapInterval = value;

	case EGL_MIN_SWAP_INTERVAL:
		return config->m_MinSwapInterval = value;

	case EGL_STENCIL_SIZE:
		return config->m_StencilSize = value;

	case EGL_DEPTH_SIZE:
		return config->m_DepthSize = value;

	case EGL_CONFIG_CAVEAT:
		return config->m_ConfigCaveat = value;

	case EGL_CONFIG_ID:
		return config->m_ConfigID = value;

	case EGL_LEVEL:
		return config->m_Level = value;

	case EGL_MAX_PBUFFER_HEIGHT:
		return config->m_MaxPBufferHeight = value;

	case EGL_MAX_PBUFFER_PIXELS:
		return config->m_MaxPBufferPixels = value;

	case EGL_MAX_PBUFFER_WIDTH:
		return config->m_MaxPBufferWidth = value;

	case EGL_NATIVE_RENDERABLE:
		return config->m_NativeRenderable = value;

	case EGL_NATIVE_VISUAL_ID:
		return config->m_NativeVisualID = value;

	case EGL_NATIVE_VISUAL_TYPE:
		return config->m_NativeVisualType = value;

	case EGL_SAMPLES:
		return config->m_Samples = value;

	case EGL_SAMPLE_BUFFERS:
		return config->m_SampleBuffers = value;

	case EGL_SURFACE_TYPE:
		return config->m_SurfaceType = value;

	case EGL_TRANSPARENT_TYPE:
		return config->m_TransparentType = value;

	case EGL_TRANSPARENT_BLUE_VALUE:
		return config->m_TransparentBlueValue = value;

	case EGL_TRANSPARENT_GREEN_VALUE:
		return config->m_TransparentGreenValue = value;

	case EGL_TRANSPARENT_RED_VALUE:
		return config->m_TransparentRedValue = value;

	case EGL_WIDTH:
		return config->m_Width = value;

	case EGL_HEIGHT:
		return config->m_Height = value;

	default:
		return EGL_NONE;
	}

	return EGL_NONE;
}