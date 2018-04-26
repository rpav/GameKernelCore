#pragma once

#if defined(_WIN32) || defined(WIN32)
#  ifdef GK_CORE_EXPORT
#    define GK_CORE_API __declspec(dllexport)
#  elif defined(GK_CORE_IMPORT)
#    define GK_CORE_API __declspec(dllimport)
#  else
#    define GK_CORE_API
#  endif
#else
#define GK_API
#endif

#include "gk/vec.h"
#include "gk/rect.h"

namespace gk {

template<typename T>
inline T lerp(T v0, T v1, float a) {
    return (v0 * (1 - a)) + (v1 * a);
}

}