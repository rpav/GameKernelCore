#pragma once

#include <gk/vec.hpp>
#include <rpav/convert.hpp>

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API trect {
    using vec2 = tvec2<T, F>;

    vec2 pos;
    vec2 size;

    constexpr trect()             = default;
    constexpr trect(const trect&) = default;
    constexpr trect(T x, T y, T w, T h) : pos(x, y), size(w, h) {}
    constexpr trect(const vec2& pos_, const vec2& size_) : pos(pos_), size(size_) {}
    constexpr trect(trect&&) = default;

    trect& operator=(const trect&) = default;
    trect& operator=(trect&&) = default;

    template<typename U, typename V>
    constexpr trect operator+(const tvec2<U, V>& v) const
    {
        return trect{pos + v, size};
    }

    template<typename U, typename V>
    constexpr trect operator-(const tvec2<U, V>& v) const
    {
        return trect{pos - v, size};
    }

    constexpr trect operator*(const F f) const { return trect{pos * f, size * f}; }

    constexpr inline vec2 v1abs() const { return vec2(pos.x + size.x, pos.y + size.y); }

    // rects are half-open
    constexpr bool contains(vec2 p) const { return (pos <= p) && ((pos + size) > p); }

    // a rect contains itself
    constexpr bool contains(const trect& r) const
    {
        return contains(pos) && ((r.size + (r.pos - pos)) <= size);
    }

    constexpr bool overlap(const trect& r) const
    {
        return (r.pos < (pos+size)) && ((r.pos+r.size) > pos);
    }

    constexpr trect floor() const { return trect{pos.floor(), size.floor()}; }
    constexpr trect ceil() const { return trect{pos.ceil(), size.ceil()}; }
    constexpr trect trunc() const { return trect{pos.trunc(), size.trunc()}; }

    // You can define conversions to other types via conv_adl<>
    template<typename To>
    explicit operator To() const
    {
        return rpav::conv_adl<trect, To>::convert(*this);
    }
};

using rect    = trect<float, float>;
using i16rect = trect<int16_t, float>;

static_assert(std::is_standard_layout_v<rect>);

} // namespace gk
