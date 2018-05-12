#pragma once

typedef struct gk_vec2 {
    float x, y;
} gk_vec2;

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

