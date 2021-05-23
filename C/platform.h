#ifndef UCRT_PLATFORM_H
#define UCRT_PLATFORM_H

// If the build system not defined macros
// we try to get them using pre-processor methods
#if !defined(ARCH_64BITS) && !defined(ARCH_32BITS)
#   if defined(__amd64__) || defined(_WIN64) || __SIZEOF_POINTER__ == 8    // 64 bits
#       define ARCH_64BITS
#   elif defined(__x86_64__) || defined(_WIN32) || __SIZEOF_POINTER__ == 4 // 32 bits
#       define ARCH_32BITS
#   else
#       error Unsupported architecture
#   endif
#endif

#if !defined(UCRT_COMPILER_DEFINED)
#   define UCRT_COMPILER_DEFINED
#   if defined(__clang__)
#       define UCRT_COMPILER_CLANG
#   elif defined(__MINGW32__) || defined(__MINGW64__)
#       define UCRT_COMPILER_MINGW
#       define UCRT_COMPILER_GCC
#   elif defined(__GNUC__) || defined(__GNUG__)
#       define UCRT_COMPILER_GCC
#   elif defined(_MSC_VER)
#       define UCRT_COMPILER_MSVC
#   else
#       undef UCRT_COMPILER_DEFINED
#       error Unsupported compiler
#   endif
#endif

#if !defined(UCRT_PLATFORM_WINDOWS) || !defined(UCRT_PLATFORM_UNIX)
#   if defined(_WIN32) || defined(_WIN64)
#       define UCRT_PLATFORM_WINDOWS
#   elif defined(unix) || defined(__unix__) || defined(__unix)
#       define UCRT_PLATFORM_UNIX
#       if defined(__linux__)
#           define UCRT_PLATFORM_LINUX
#       elif defined(__APPLE__)
#           define UCRT_PLATFORM_APPLE
#       elif defined(__ANDROID__)
#           define UCRT_PLATFORM_ANDROID
#       elif defined(__FreeBSD__)
#           define UCRT_PLATFORM_FREEBSD
#       elif defined(__OpenBSD__)
#           define UCRT_PLATFORM_OPENBSD
#       endif
#   else
#       error Unsupported platform
#   endif
#endif

#endif // UCRT_PLATFORM_H
