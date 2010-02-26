#include <stdlib.h>
#include <string.h>

#include "EGL/egl.h"
#include "errlog.h"
#include "config.h"
#include "display.h"

#define MAX_CONFIGS 10

typedef struct _config
{
	EGLint	    m_BufferSize;
	EGLint	    m_RedSize;
	EGLint	    m_GreenSize;
	EGLint	    m_BlueSize;
	EGLint	    m_LuminanceSize;
	EGLint	    m_AlphaSize;
	EGLint	    m_AlphaMaskSize;
	EGLBoolean  m_BindToTextureRGB;
    EGLBoolean  m_BindToTextureRGBA;
    EGLint      m_ColorBufferType;
	EGLint	    m_ConfigCaveat;
	EGLint	    m_ConfigID;
    EGLint      m_Conformat;
	EGLint	    m_DepthSize;
	EGLint	    m_Level;
	EGLint	    m_MaxPBufferWidth;
	EGLint	    m_MaxPBufferHeight;
	EGLint	    m_MaxPBufferPixels;
    EGLint      m_MaxSwapInterval;
    EGLint      m_MinSwapInterval;
	EGLint	    m_NativeRenderable;
	EGLint	    m_NativeVisualID;
	EGLint	    m_NativeVisualType;
    EGLint      m_RenderableType;
	EGLint	    m_SampleBuffers;
	EGLint	    m_Samples;
	EGLint	    m_StencilSize;
	EGLint	    m_SurfaceType;
	EGLint	    m_TransparentType;
	EGLint	    m_TransparentRedValue;
	EGLint	    m_TransparentGreenValue;
	EGLint	    m_TransparentBlueValue;
	EGLint      m_Width;
	EGLint	    m_Height;
}CONFIG;

typedef struct _config_management
{
	CONFIG s_AllConfigurations[MAX_CONFIGS];	
	EGLint s_NumConfigurations;
}CONFIG_MANAGEMENT;

static CONFIG_MANAGEMENT cfg_management;

EGLBoolean cfgInitManagement ()
{
	cfg_management.s_NumConfigurations = 0;
	return EGL_TRUE;
}

EGLBoolean cfgInitConfig(EGLConfig config,
							EGLint	    BufferSize,
							EGLint	    RedSize,
							EGLint	    GreenSize,
							EGLint	    BlueSize,
							EGLint	    LuminanceSize,
							EGLint	    AlphaSize,
							EGLint	    AlphaMaskSize,
							EGLBoolean  BindToTextureRGB,
							EGLBoolean  BindToTextureRGBA,
							EGLint      ColorBufferType,
							EGLint	    ConfigCaveat,
							EGLint	    ConfigID,
							EGLint      Conformat,
							EGLint	    DepthSize,
							EGLint	    Level,
							EGLint	    MaxPBufferWidth,
							EGLint	    MaxPBufferHeight,
							EGLint	    MaxPBufferPixels,
							EGLint      MaxSwapInterval,
							EGLint      MinSwapInterval,
							EGLint	    NativeRenderable,
							EGLint	    NativeVisualID,
							EGLint	    NativeVisualType,
							EGLint      RenderableType,
							EGLint	    SampleBuffers,
							EGLint	    Samples,
							EGLint	    StencilSize,
							EGLint	    SurfaceType,
							EGLint	    TransparentType,
							EGLint	    TransparentRedValue,
							EGLint	    TransparentGreenValue,
							EGLint	    TransparentBlueValue,
							EGLint      Width,
							EGLint	    Height)
{
	CONFIG* cfg = (CONFIG*)config;

	if (NULL == cfg)
	{
		return EGL_FALSE;
	}

	cfg->m_BufferSize =				BufferSize;
	cfg->m_RedSize =				RedSize;
	cfg->m_GreenSize =				GreenSize;
	cfg->m_BlueSize =				BlueSize;
	cfg->m_LuminanceSize =			LuminanceSize;
	cfg->m_AlphaSize =				AlphaSize;
	cfg->m_AlphaMaskSize =			AlphaMaskSize;
	cfg->m_BindToTextureRGB =		BindToTextureRGB;
	cfg->m_BindToTextureRGBA =		BindToTextureRGBA;
	cfg->m_ColorBufferType =		ColorBufferType;
	cfg->m_ConfigCaveat =			ConfigCaveat;
	cfg->m_ConfigID =				ConfigID;
	cfg->m_Conformat =				Conformat;
	cfg->m_DepthSize =				DepthSize;
	cfg->m_Level =					Level;
	cfg->m_MaxPBufferWidth =		MaxPBufferWidth;
	cfg->m_MaxPBufferHeight =		MaxPBufferHeight;
	cfg->m_MaxPBufferPixels =		MaxPBufferPixels;
	cfg->m_MaxSwapInterval =		MaxSwapInterval;
	cfg->m_MinSwapInterval =		MinSwapInterval;
	cfg->m_NativeRenderable =		NativeRenderable;
	cfg->m_NativeVisualID =			NativeVisualID;
	cfg->m_NativeVisualType =		NativeVisualType;
	cfg->m_RenderableType =			RenderableType;
	cfg->m_SampleBuffers =			SampleBuffers;
	cfg->m_Samples =				Samples;
	cfg->m_StencilSize =			StencilSize;
	cfg->m_SurfaceType =			SurfaceType;
	cfg->m_TransparentType =		TransparentType;
	cfg->m_TransparentRedValue =	TransparentRedValue;
	cfg->m_TransparentGreenValue =	TransparentGreenValue;
	cfg->m_TransparentBlueValue =	TransparentBlueValue;
	cfg->m_Width =					Width;
	cfg->m_Height =					Height;

	return EGL_TRUE;
}


EGLBoolean cfgAddDefaultConfig(EGLint	    BufferSize,
							EGLint	    RedSize,
							EGLint	    GreenSize,
							EGLint	    BlueSize,
							EGLint	    LuminanceSize,
							EGLint	    AlphaSize,
							EGLint	    AlphaMaskSize,
							EGLBoolean  BindToTextureRGB,
							EGLBoolean  BindToTextureRGBA,
							EGLint      ColorBufferType,
							EGLint	    ConfigCaveat,
							EGLint      Conformat,
							EGLint	    DepthSize,
							EGLint	    Level,
							EGLint	    MaxPBufferWidth,
							EGLint	    MaxPBufferHeight,
							EGLint	    MaxPBufferPixels,
							EGLint      MaxSwapInterval,
							EGLint      MinSwapInterval,
							EGLint	    NativeRenderable,
							EGLint	    NativeVisualID,
							EGLint	    NativeVisualType,
							EGLint      RenderableType,
							EGLint	    SampleBuffers,
							EGLint	    Samples,
							EGLint	    StencilSize,
							EGLint	    SurfaceType,
							EGLint	    TransparentType,
							EGLint	    TransparentRedValue,
							EGLint	    TransparentGreenValue,
							EGLint	    TransparentBlueValue,
							EGLint      Width,
							EGLint	    Height)
{
	EGLBoolean ret;
	if (cfg_management.s_NumConfigurations > MAX_CONFIGS)
	{
		return EGL_FALSE;
	}

	ret = cfgInitConfig((EGLConfig)&cfg_management.s_AllConfigurations[cfg_management.s_NumConfigurations],
							BufferSize,
							RedSize,
							GreenSize,
							BlueSize,
							LuminanceSize,
							AlphaSize,
							AlphaMaskSize,
							BindToTextureRGB,
							BindToTextureRGBA,
							ColorBufferType,
							ConfigCaveat,
							cfg_management.s_NumConfigurations + 1,
							Conformat,
							DepthSize,
							Level,
							MaxPBufferWidth,
							MaxPBufferHeight,
							MaxPBufferPixels,
							MaxSwapInterval,
							MinSwapInterval,
							NativeRenderable,
							NativeVisualID,
							NativeVisualType,
							RenderableType,
							SampleBuffers,
							Samples,
							StencilSize,
							SurfaceType,
							TransparentType,
							TransparentRedValue,
							TransparentGreenValue,
							TransparentBlueValue,
							Width,
							Height);
	if (EGL_FALSE == ret)
	{
		return EGL_FALSE;
	}

	cfg_management.s_NumConfigurations ++;
	return EGL_TRUE;
}


EGLBoolean GetConfigs(EGLConfig * result, EGLint configSize, EGLint * numConfig)
{
	if (result == 0)
	{
		// special case: inquire number of configurations available
		*numConfig = cfg_management.s_NumConfigurations;
		return EGL_TRUE;
	}

	if (configSize > cfg_management.s_NumConfigurations)
	{
		configSize = cfg_management.s_NumConfigurations;
	}

	//fixme
	//for (index = 0; index < configSize; ++index)
	{
		result[0] = &cfg_management.s_AllConfigurations;
	}

	*numConfig = configSize;
	return EGL_TRUE;
}

EGLConfig cfgGet(EGLint configId)
{
	if (configId >= cfg_management.s_NumConfigurations || configId < 0)
	{
		return (EGLConfig)NULL;
	}

	return (EGLConfig)&cfg_management.s_AllConfigurations[configId - 1];
}

EGLBoolean ChooseConfig(const EGLint * attribList, EGLConfig * result, EGLint configSize, EGLint * numConfig)
{
	// for now, as we only have one configuration available, just return that.
	// to be a correct implementation, we will have at least to verify that
	// the attributes specified match that.
	return GetConfigs(result, configSize, numConfig);
}

EGLint cfgGetAttrib(EGLConfig config, EGLint attribute)
{
	CONFIG* cfg = (CONFIG*) config;

	switch (attribute)
	{
	case EGL_BUFFER_SIZE:
		return cfg->m_BufferSize;

	case EGL_ALPHA_SIZE:
		return cfg->m_AlphaSize;

	case EGL_BLUE_SIZE:
		return cfg->m_BlueSize;

	case EGL_GREEN_SIZE:
		return cfg->m_GreenSize;

	case EGL_RED_SIZE:
		return cfg->m_RedSize;

	case EGL_LUMINANCE_SIZE:
		return cfg->m_LuminanceSize;

	case EGL_ALPHA_MASK_SIZE:
		return cfg->m_AlphaMaskSize;

	case EGL_BIND_TO_TEXTURE_RGB:
		return cfg->m_BindToTextureRGB;

	case EGL_BIND_TO_TEXTURE_RGBA:
		return cfg->m_BindToTextureRGBA;

	case EGL_COLOR_BUFFER_TYPE:
		return cfg->m_ColorBufferType;

	case EGL_RENDERABLE_TYPE:
		return cfg->m_RenderableType;
	
	case EGL_CONFORMANT:
		return cfg->m_Conformat;

	case EGL_MAX_SWAP_INTERVAL:
		return cfg->m_MaxSwapInterval;

	case EGL_MIN_SWAP_INTERVAL:
		return cfg->m_MinSwapInterval;

	case EGL_STENCIL_SIZE:
		return cfg->m_StencilSize;

	case EGL_DEPTH_SIZE:
		return cfg->m_DepthSize;

	case EGL_CONFIG_CAVEAT:
		return cfg->m_ConfigCaveat;

	case EGL_CONFIG_ID:
		return cfg->m_ConfigID;

	case EGL_LEVEL:
		return cfg->m_Level;

	case EGL_MAX_PBUFFER_HEIGHT:
		return cfg->m_MaxPBufferHeight;

	case EGL_MAX_PBUFFER_PIXELS:
		return cfg->m_MaxPBufferPixels;

	case EGL_MAX_PBUFFER_WIDTH:
		return cfg->m_MaxPBufferWidth;

	case EGL_NATIVE_RENDERABLE:
		return cfg->m_NativeRenderable;

	case EGL_NATIVE_VISUAL_ID:
		return cfg->m_NativeVisualID;

	case EGL_NATIVE_VISUAL_TYPE:
		return cfg->m_NativeVisualType;

	case EGL_SAMPLES:
		return cfg->m_Samples;

	case EGL_SAMPLE_BUFFERS:
		return cfg->m_SampleBuffers;

	case EGL_SURFACE_TYPE:
		return cfg->m_SurfaceType;

	case EGL_TRANSPARENT_TYPE:
		return cfg->m_TransparentType;

	case EGL_TRANSPARENT_BLUE_VALUE:
		return cfg->m_TransparentBlueValue;

	case EGL_TRANSPARENT_GREEN_VALUE:
		return cfg->m_TransparentGreenValue;

	case EGL_TRANSPARENT_RED_VALUE:
		return cfg->m_TransparentRedValue;

	case EGL_WIDTH:
		return cfg->m_Width;

	case EGL_HEIGHT:
		return cfg->m_Height;

	default:
		return EGL_NONE;
	}

	return EGL_NONE;
}

EGLint cfgSetAttrib(EGLConfig config, EGLint attribute, EGLint value)
{
	CONFIG* cfg = (CONFIG*) config;

	switch (attribute)
	{
	case EGL_BUFFER_SIZE:
		return cfg->m_BufferSize = value;

	case EGL_ALPHA_SIZE:
		return cfg->m_AlphaSize = value;

	case EGL_BLUE_SIZE:
		return cfg->m_BlueSize = value;

	case EGL_GREEN_SIZE:
		return cfg->m_GreenSize = value;

	case EGL_RED_SIZE:
		return cfg->m_RedSize = value;

	case EGL_LUMINANCE_SIZE:
		return cfg->m_LuminanceSize = value;

	case EGL_ALPHA_MASK_SIZE:
		return cfg->m_AlphaMaskSize = value;

	case EGL_BIND_TO_TEXTURE_RGB:
		return cfg->m_BindToTextureRGB = value;

	case EGL_BIND_TO_TEXTURE_RGBA:
		return cfg->m_BindToTextureRGBA = value;

	case EGL_COLOR_BUFFER_TYPE:
		return cfg->m_ColorBufferType = value;

	case EGL_RENDERABLE_TYPE:
		return cfg->m_RenderableType = value;
	
	case EGL_CONFORMANT:
		return cfg->m_Conformat = value;

	case EGL_MAX_SWAP_INTERVAL:
		return cfg->m_MaxSwapInterval = value;

	case EGL_MIN_SWAP_INTERVAL:
		return cfg->m_MinSwapInterval = value;

	case EGL_STENCIL_SIZE:
		return cfg->m_StencilSize = value;

	case EGL_DEPTH_SIZE:
		return cfg->m_DepthSize = value;

	case EGL_CONFIG_CAVEAT:
		return cfg->m_ConfigCaveat = value;

	case EGL_CONFIG_ID:
		return cfg->m_ConfigID = value;

	case EGL_LEVEL:
		return cfg->m_Level = value;

	case EGL_MAX_PBUFFER_HEIGHT:
		return cfg->m_MaxPBufferHeight = value;

	case EGL_MAX_PBUFFER_PIXELS:
		return cfg->m_MaxPBufferPixels = value;

	case EGL_MAX_PBUFFER_WIDTH:
		return cfg->m_MaxPBufferWidth = value;

	case EGL_NATIVE_RENDERABLE:
		return cfg->m_NativeRenderable = value;

	case EGL_NATIVE_VISUAL_ID:
		return cfg->m_NativeVisualID = value;

	case EGL_NATIVE_VISUAL_TYPE:
		return cfg->m_NativeVisualType = value;

	case EGL_SAMPLES:
		return cfg->m_Samples = value;

	case EGL_SAMPLE_BUFFERS:
		return cfg->m_SampleBuffers = value;

	case EGL_SURFACE_TYPE:
		return cfg->m_SurfaceType = value;

	case EGL_TRANSPARENT_TYPE:
		return cfg->m_TransparentType = value;

	case EGL_TRANSPARENT_BLUE_VALUE:
		return cfg->m_TransparentBlueValue = value;

	case EGL_TRANSPARENT_GREEN_VALUE:
		return cfg->m_TransparentGreenValue = value;

	case EGL_TRANSPARENT_RED_VALUE:
		return cfg->m_TransparentRedValue = value;

	case EGL_WIDTH:
		return cfg->m_Width = value;

	case EGL_HEIGHT:
		return cfg->m_Height = value;

	default:
		return EGL_NONE;
	}

	return EGL_NONE;
}

EGLConfig cfgCreate()
{
	CONFIG* cfg = NULL;

	cfg = (CONFIG*) malloc (sizeof (CONFIG));
	if (NULL == cfg)
	{
		eglRecordError(EGL_BAD_ALLOC);
		return (EGLConfig) NULL;
	}

	memset (cfg, 0, sizeof(CONFIG));

	return (EGLConfig)cfg;
}

EGLBoolean cfgDestroy(EGLConfig config)
{
	CONFIG* cfg = (CONFIG*) config;

	if (NULL == cfg)
	{
		return EGL_FALSE;
	}

	free (cfg);
	return EGL_TRUE;
}

EGLBoolean cfgClone(EGLConfig dst_config, EGLConfig src_config)
{
	CONFIG *src, *dst;

	src = (CONFIG*) src_config;
	dst = (CONFIG*) dst_config;

	if (src == NULL || dst == NULL)
	{
		return EGL_FALSE;
	}

	memcpy (dst, src, sizeof (CONFIG));

	return EGL_TRUE;
}