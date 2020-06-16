#pragma once

#include <algorithm>

#include <gk/vec.hpp>
#include <rpav/convert.hpp>

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API trect {
    using vec2 = tvec2<T, F>;
    using vec4 = tvec4<T, F>;

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

    constexpr trect operator*(const mat4& m) const
    {
        auto newPos  = m * vec4(pos, 0, 1);
        auto newSize = m * vec4(size, 0, 0);
        return {{newPos.x, newPos.y}, {newSize.x, newSize.y}};
    }

    constexpr inline vec2 v1abs() const { return vec2(pos.x + size.x, pos.y + size.y); }

    // rects are half-open
    constexpr bool contains(vec2 p) const { return (pos <= p) && ((pos + size) > p); }

    // a rect contains itself
    constexpr bool contains(const trect& r) const { return contains(pos) && ((r.size + (r.pos - pos)) <= size); }

    constexpr bool overlap(const trect& r) const { return (r.pos < (pos + size)) && ((r.pos + r.size) > pos); }

    // The smallest rect that contains this rect and r
    constexpr trect combine(const trect& r) const
    {
        auto minx = std::min(pos.x, r.pos.x);
        auto miny = std::min(pos.y, r.pos.y);
        auto maxx = std::max(pos.x + size.x, r.pos.x + r.size.x);
        auto maxy = std::max(pos.y + size.y, r.pos.y + r.size.y);

        return {minx, miny, maxx - minx, maxy - miny};
    }

    constexpr trect floor() const { return trect{pos.floor(), size.floor()}; }
    constexpr trect ceil() const { return trect{pos.ceil(), size.ceil()}; }
    constexpr trect trunc() const { return trect{pos.trunc(), size.trunc()}; }

    constexpr vec2 center() const { return {pos.x + (size.x / 2), pos.y + (size.y / 2)}; }

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
