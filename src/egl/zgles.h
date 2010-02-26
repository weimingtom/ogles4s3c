#ifndef __ZGLES_H__
#define __ZGLES_H__

// version numbers
#define EGL_VERSION_MAJOR 1
#define EGL_VERSION_MINOR 4

#ifndef EGL_RELEASE
#	define EGL_RELEASE				"1.4"
#endif

#define EGL_CONFIG_VENDOR			"CPSOFT"

#ifdef COMMON_LITE
#	define EGL_CONFIG_VERSION			"OpenGL ES-CL 1.1"
#else
#	define EGL_CONFIG_VERSION			"OpenGL ES-CM 1.1"
#endif

#define EGL_CONFIG_EXTENSIONS		"GL_OES_fixed_point "\
									"GL_OES_single_precision "\
									"GL_OES_read_format "\
									"GL_OES_query_matrix "\
									"GL_OES_point_size_array "\
									"GL_OES_point_sprite "\
									"GL_OES_compressed_paletted_texture"

#define EGL_CLIENT_STRING			"OpenGL_ES"

#define EGL_CONFIG_RENDERER		"hardware"

#define EGL_VERSION_NUMBER			EGL_RELEASE " " EGL_CONFIG_RENDERER

#endif