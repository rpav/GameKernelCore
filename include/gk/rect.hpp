#pragma once

#include "gk/vec.hpp"

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API trect {
    using vec2 = tvec2<T,F>;

    vec2 pos;
    vec2 size;

    trect() = default;
    trect(const trect &r) { pos = r.pos; size = r.size; }
    trect(T x, T y, T w, T h)
        : pos(x, y), size(w, h) {
    }
    trect(const vec2 &pos_, const vec2 &size_)
        : pos(pos_), size(size_) {
    }

    trect& operator=(const trect &r) { pos = r.pos; size = r.size; return *this; }

    template<typename U, typename V>
    trect operator+(const tvec2<U,V> &v) const { return trect{pos + v, size}; }

    template<typename U, typename V>
    trect operator-(const tvec2<U,V> &v) const { return trect{pos - v, size}; }

    inline vec2 v1abs() const { return vec2(pos.x + size.x, pos.y + size.y); }

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
