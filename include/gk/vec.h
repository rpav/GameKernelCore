#pragma once

#ifdef __cplusplus
    #error "For C++, use gk/vec.hpp instead of gk/vec.h, or gk/core.hpp instead of gk/core.h"
#endif

typedef struct gk_vec2 {
    float x, y;
} gk_vec2;

typedef struct gk_ivec2 {
    int32_t x, y;
} gk_ivec2;

typedef struct gk_vec3 {
    float x, y, z;
} gk_vec3;

typedef struct gk_vec4 {
    float x, y, z, w;
} gk_vec4;

typedef struct gk_mat4 {
    float a00, a01, a02, a03;
    float a10, a11, a12, a13;
    float a20, a21, a22, a23;
    float a30, a31, a32, a33;
} gk_mat4;
