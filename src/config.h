#ifndef __CONFIG_H__
#define __CONFIG_H__

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


EGLBoolean GetConfigs(EGLConfig * result, EGLint configSize, EGLint * numConfig);
EGLBoolean ChooseConfig(const EGLint * attribList, EGLConfig * result, EGLint configSize, EGLint * numConfig);
EGLint GetConfigAttrib(EGLDisplay dpy, CONFIG* config, EGLint attribute);
EGLint SetConfigAttrib(EGLDisplay dpy, CONFIG* config, EGLint attribute, EGLint value);

#endif