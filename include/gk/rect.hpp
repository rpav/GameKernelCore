#pragma once

#include "gk/vec.hpp"

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API trect {
    vec2 pos;
    vec2 size;

    trect() = default;
    trect(const trect &r) { pos = r.pos; size = r.size; }
    trect(float x, float y, float w, float h)
        : pos(x, y), size(w, h) {
    }
    trect(const vec2 &pos_, const vec2 &size_)
        : pos(pos_), size(size_) {
    }

    trect& operator=(const trect &r) { pos = r.pos; size = r.size; return *this; }

    inline gk::vec2 v1abs() const { return gk::vec2(pos.x + size.x, pos.y + size.y); }

    bool contains(const vec2 &p) const {
        return (pos.x <= p.x) && (pos.y <= p.y) &&
               (pos.x+size.x > p.x) && (pos.y+size.y > p.y);
    }

    trect& floor() {
        pos.floor();
        size.floor();
        return *this;
    }

    trect& ceil() {
        pos.ceil();
        size.ceil();
        return *this;
    }

    trect& trunc() {
        pos.trunc();
        size.trunc();
        return *this;
    }
};

using rect = trect<float,float>;
using i16rect = trect<int16_t, float>;

static_assert(std::is_standard_layout_v<rect>);

}
