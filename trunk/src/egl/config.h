#ifndef __CONFIG_H__
#define __CONFIG_H__


EGLBoolean cfgInitManagement ();
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
							EGLint	    Height);

EGLConfig cfgGet(EGLint configId);
EGLBoolean GetConfigs(EGLConfig * result, EGLint configSize, EGLint * numConfig);
EGLBoolean ChooseConfig(const EGLint * attribList, EGLConfig * result, EGLint configSize, EGLint * numConfig);
EGLint cfgGetAttrib(EGLConfig config, EGLint attribute);
EGLint cfgSetAttrib(EGLConfig config, EGLint attribute, EGLint value);

EGLConfig cfgCreate();
EGLBoolean cfgDestroy(EGLConfig config);
EGLBoolean cfgClone(EGLConfig dst_config, EGLConfig src_config);

#endif