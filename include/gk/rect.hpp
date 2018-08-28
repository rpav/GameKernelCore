#pragma once

#include <rpav/convert.hpp>
#include <gk/vec.hpp>

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API trect {
    using vec2 = tvec2<T,F>;

    vec2 pos;
    vec2 size;

    constexpr trect() = default;
    constexpr trect(const trect &r) { pos = r.pos; size = r.size; }
    constexpr trect(T x, T y, T w, T h)
        : pos(x, y), size(w, h) {
    }
    constexpr trect(const vec2 &pos_, const vec2 &size_)
        : pos(pos_), size(size_) {
    }

    trect& operator=(const trect &r) { pos = r.pos; size = r.size; return *this; }

    template<typename U, typename V>
    constexpr trect operator+(const tvec2<U,V> &v) const { return trect{pos + v, size}; }

    template<typename U, typename V>
    constexpr trect operator-(const tvec2<U,V> &v) const { return trect{pos - v, size}; }

    constexpr inline vec2 v1abs() const { return vec2(pos.x + size.x, pos.y + size.y); }

    constexpr bool contains(vec2 p) const {
        return (pos.x <= p.x) && (pos.y <= p.y) &&
               (pos.x+size.x > p.x) && (pos.y+size.y > p.y);
    }

    constexpr trect floor() const { return trect{pos.floor(), size.floor()}; }
    constexpr trect ceil() const { return trect{pos.ceil(), size.ceil()}; }
    constexpr trect trunc() const { return trect{pos.trunc(), size.trunc() }; }

    // You can define conversions to other types via conv_adl<>
    template<typename To>
    explicit operator To() const { return rpav::conv_adl<trect,To>::convert(*this); }
};

using rect = trect<float,float>;
using i16rect = trect<int16_t, float>;

static_assert(std::is_standard_layout_v<rect>);

}
