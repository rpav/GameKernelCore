#pragma once

#include "gk/vec.h"

typedef struct gk_rect {
    gk_vec2 pos;
    gk_vec2 size;
} gk_rect;

typedef struct gk_irect {
    gk_ivec2 pos;
    gk_ivec2 size;
} gk_irect;
