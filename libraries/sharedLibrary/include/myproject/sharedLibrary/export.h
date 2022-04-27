
#ifndef MYPROJECT_SHAREDLIBRARY_EXPORT_H
#define MYPROJECT_SHAREDLIBRARY_EXPORT_H

#ifdef MYPROJECT_SHAREDLIBRARY_STATIC_DEFINE
#  define MYPROJECT_SHAREDLIBRARY_EXPORT
#  define MYPROJECT_SHAREDLIBRARY_NO_EXPORT
#else
#  ifndef MYPROJECT_SHAREDLIBRARY_EXPORT
#    ifdef myproject_sharedlibrary_EXPORTS
        /* We are building this library */
#      define MYPROJECT_SHAREDLIBRARY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MYPROJECT_SHAREDLIBRARY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MYPROJECT_SHAREDLIBRARY_NO_EXPORT
#    define MYPROJECT_SHAREDLIBRARY_NO_EXPORT 
#  endif
#endif

#ifndef MYPROJECT_SHAREDLIBRARY_DEPRECATED
#  define MYPROJECT_SHAREDLIBRARY_DEPRECATED __declspec(deprecated)
#endif

#ifndef MYPROJECT_SHAREDLIBRARY_DEPRECATED_EXPORT
#  define MYPROJECT_SHAREDLIBRARY_DEPRECATED_EXPORT MYPROJECT_SHAREDLIBRARY_EXPORT MYPROJECT_SHAREDLIBRARY_DEPRECATED
#endif

#ifndef MYPROJECT_SHAREDLIBRARY_DEPRECATED_NO_EXPORT
#  define MYPROJECT_SHAREDLIBRARY_DEPRECATED_NO_EXPORT MYPROJECT_SHAREDLIBRARY_NO_EXPORT MYPROJECT_SHAREDLIBRARY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MYPROJECT_SHAREDLIBRARY_NO_DEPRECATED
#    define MYPROJECT_SHAREDLIBRARY_NO_DEPRECATED
#  endif
#endif

#endif /* MYPROJECT_SHAREDLIBRARY_EXPORT_H */
