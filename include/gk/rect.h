#ifndef __GAMEKERNELCORE_RECT_H__
#define __GAMEKERNELCORE_RECT_H__

#include "gk/vec.h"

#ifdef __cplusplus
#  define GK_CXX_API GK_API
#else
#  define GK_CXX_API
#endif

typedef struct gk_rect {
    gk_vec2 pos;
    gk_vec2 size;

#ifdef __cplusplus
    gk_rect() = default;
    gk_rect(const gk_rect &r) { pos = r.pos; size = r.size; }
    gk_rect(int) : pos(0), size(0) {}
    gk_rect(float x, float y, float w, float h)
        : pos(x, y), size(w, h) {
    }
    gk_rect(const gk_vec2 &pos_, const gk_vec2 &size_)
        : pos(pos_), size(size_) {
    }

    gk_rect& operator=(const gk_rect &r) { pos = r.pos; size = r.size; return *this; }

    inline gk::vec2 v1abs() const { return gk::vec2(pos.x + size.x, pos.y + size.y); }
#endif // __cplusplus
} gk_rect;

#ifdef __cplusplus
namespace gk {
    using rect = gk_rect;
}
#endif // __cplusplus

#endif /* __GAMEKERNELCORE_RECT_H__ */
