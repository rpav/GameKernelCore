#pragma once

#define GK_CORE_CXX_API
#include <cmath>
#include <cstring>
#include <type_traits>

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API tvec2 {
    using element_type = T;
    using float_type   = F;

    T x{0}, y{0};

    constexpr tvec2()               = default;
    constexpr tvec2(const tvec2& v) = default;
    constexpr tvec2(T x_, T y_) : x(x_), y(y_) {}

    constexpr tvec2 operator-() const { return tvec2(-x, -y); }

    constexpr tvec2 operator+(tvec2 v) const { return tvec2(x + v.x, y + v.y); }
    constexpr tvec2 operator-(tvec2 v) const { return tvec2(x - v.x, y - v.y); }
    constexpr tvec2 operator+(float f) const { return tvec2(x + f, y + f); }
    constexpr tvec2 operator-(float f) const { return tvec2(x - f, y - f); }
    constexpr tvec2 operator*(float f) const { return tvec2(x * f, y * f); }
    constexpr tvec2 operator*(tvec2 v) const { return tvec2(x * v.x, y * v.y); }
    constexpr tvec2 operator/(float f) const { return tvec2(x / f, y / f); }
    constexpr tvec2 operator/(tvec2 v) const { return tvec2(x / v.x, y / v.y); }

    constexpr inline bool operator==(tvec2 v) const { return (x == v.x && y == v.y); }
    constexpr inline bool operator!=(tvec2 v) const { return !(*this == v); }

    tvec2& operator+=(tvec2 v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    tvec2& operator-=(tvec2 v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    tvec2& operator+=(float f)
    {
        x += f;
        y += f;
        return *this;
    }

    tvec2& operator-=(float f)
    {
        x -= f;
        y -= f;
        return *this;
    }

    tvec2& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }

    tvec2& operator*=(tvec2 v)
    {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    tvec2& operator/=(float f)
    {
        x /= f;
        y /= f;
        return *this;
    }

    tvec2& operator/=(tvec2 v) const
    {
        x /= v.x;
        y /= v.y;
        return *this;
    }

    tvec2& operator=(tvec2 v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    void set(T* f)
    {
        x = f[0];
        y = f[1];
    }

    // Note: These are simple but not terribly efficient

    // Requires a normalized vector
    constexpr F angle(tvec2 v) const { return std::atan2(v.y, v.x) - std::atan2(y, x); }
    constexpr F length() const { return std::sqrt((x * x) + (y * y)); }

    constexpr tvec2 normalize()
    {
        F scale = F(1.0) / length();
        return tvec2{x * scale, y * scale};
    }

    constexpr tvec2 rotate(F radians) const
    {
        F c = std::cos(radians);
        F s = std::sin(radians);
        return tvec2{x * c - y * s, x * s + y * c};
    }

    constexpr F     dot(tvec2 v) const { return (x * v.x) + (y * v.y); }
    constexpr tvec2 floor() const { return {std::floor(x), std::floor(y)}; }
    constexpr tvec2 ceil() const { return {std::ceil(x), std::ceil(y)}; }
    constexpr tvec2 trunc() const { return {std::trunc(x), std::trunc(y)}; }
};

using vec2    = tvec2<float, float>;
using i16vec2 = tvec2<int16_t, float>;

template<typename T, typename F>
struct GK_CORE_CXX_API tvec3 {
    T x{0}, y{0}, z{0};

    constexpr tvec3() = default;
    constexpr tvec3(T x, T y, T z) : x(x), y(y), z(z) {}

    constexpr tvec3 operator+(tvec3 v) const { return tvec3(x + v.x, y + v.y, z + v.z); }

    tvec3& operator+=(tvec3 v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    constexpr tvec3 operator-(tvec3 v) const { return tvec3(x - v.x, y - v.y, z - v.z); }

    tvec3& operator-=(tvec3 v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    constexpr F length() const { return std::sqrt((x * x) + (y * y) + (z * z)); }

    constexpr tvec3 normalize() const
    {

        const F scale = F(1.0) / length();
        tvec3   out{x * scale, y * scale, z * scale};
        return out;
    }

    void set(const T* f)
    {
        x = f[0];
        y = f[1];
        z = f[2];
    }
};

using vec3 = tvec3<float, float>;

template<typename T, typename F>
struct GK_CORE_CXX_API tvec4 {
    T x{0}, y{0}, z{0}, w{0};

    constexpr tvec4() = default;
    constexpr tvec4(T x_, T y_, T z_, T w_)
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }

    constexpr tvec4 operator+(tvec4 v) const
    {
        return tvec4(x + v.x, y + v.y, z + v.z, w + v.w);
    }
    tvec4& operator+=(tvec4 v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }

    constexpr tvec4 operator-(tvec4 v) const
    {
        return tvec4(x - v.x, y - v.y, z - v.z, w - v.w);
    }
    tvec4& operator-=(tvec4 v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }

    void set(const T* f)
    {
        x = f[0];
        y = f[1];
        z = f[2];
        w = f[3];
    }
};

using vec4 = tvec4<float, float>;

struct GK_CORE_CXX_API mat4 {
    float a00{1}, a01{0}, a02{0}, a03{0};
    float a10{0}, a11{1}, a12{0}, a13{0};
    float a20{0}, a21{0}, a22{1}, a23{0};
    float a30{0}, a31{0}, a32{0}, a33{1};

    constexpr mat4() = default;

    constexpr mat4(const mat4& m)
    {
        a00 = m.a00;
        a01 = m.a01;
        a02 = m.a02;
        a03 = m.a03;
        a10 = m.a10;
        a11 = m.a11;
        a02 = m.a12;
        a03 = m.a13;
        a20 = m.a20;
        a21 = m.a21;
        a02 = m.a22;
        a03 = m.a23;
        a30 = m.a30;
        a31 = m.a31;
        a02 = m.a32;
        a03 = m.a33;
    }
    void set(const float* f) { std::memcpy(this, f, sizeof(*this)); }

    constexpr vec4 operator*(vec4 v) const
    {
        vec4 out;
        out.x = (a00 * v.x) + (a01 * v.y) + (a02 * v.z) + (a03 * v.w);
        out.y = (a10 * v.x) + (a11 * v.y) + (a12 * v.z) + (a13 * v.w);
        out.z = (a20 * v.x) + (a21 * v.y) + (a22 * v.z) + (a23 * v.w);
        out.w = (a30 * v.x) + (a31 * v.y) + (a32 * v.z) + (a33 * v.w);
        return out;
    }

    constexpr mat4 operator*(const mat4& m) const
    {
        mat4 out;
        out.a00 = (a00 * m.a00) + (a01 * m.a10) + (a02 * m.a20) + (a03 * m.a30);
        out.a01 = (a00 * m.a01) + (a01 * m.a11) + (a02 * m.a21) + (a03 * m.a31);
        out.a02 = (a00 * m.a02) + (a01 * m.a12) + (a02 * m.a22) + (a03 * m.a32);
        out.a03 = (a00 * m.a03) + (a01 * m.a13) + (a02 * m.a23) + (a03 * m.a33);

        out.a10 = (a10 * m.a00) + (a11 * m.a10) + (a12 * m.a20) + (a13 * m.a30);
        out.a11 = (a10 * m.a01) + (a11 * m.a11) + (a12 * m.a21) + (a13 * m.a31);
        out.a12 = (a10 * m.a02) + (a11 * m.a12) + (a12 * m.a22) + (a13 * m.a32);
        out.a13 = (a10 * m.a03) + (a11 * m.a13) + (a12 * m.a23) + (a13 * m.a33);

        out.a20 = (a20 * m.a00) + (a21 * m.a10) + (a22 * m.a20) + (a23 * m.a30);
        out.a21 = (a20 * m.a01) + (a21 * m.a11) + (a22 * m.a21) + (a23 * m.a31);
        out.a22 = (a20 * m.a02) + (a21 * m.a12) + (a22 * m.a22) + (a23 * m.a32);
        out.a23 = (a20 * m.a03) + (a21 * m.a13) + (a22 * m.a23) + (a23 * m.a33);

        out.a30 = (a30 * m.a00) + (a31 * m.a10) + (a32 * m.a20) + (a33 * m.a30);
        out.a31 = (a30 * m.a01) + (a31 * m.a11) + (a32 * m.a21) + (a33 * m.a31);
        out.a32 = (a30 * m.a02) + (a31 * m.a12) + (a32 * m.a22) + (a33 * m.a32);
        out.a33 = (a30 * m.a03) + (a31 * m.a13) + (a32 * m.a23) + (a33 * m.a33);

        return out;
    }

    constexpr static mat4 translate(vec3 t)
    {
        mat4 out;
        out.a03 = t.x;
        out.a13 = t.y;
        out.a23 = t.z;
        return out;
    }

    // This *assumes* a normalized vec3
    constexpr static mat4 rotate(float angle, vec3 axis)
    {
        mat4       out;
        const auto cos = std::cos(angle);
        const auto sin = std::sin(angle);
        const auto x   = axis.x;
        const auto y   = axis.y;
        const auto z   = axis.z;

        out.a00 = cos + (x * x) * (1 - cos);
        out.a01 = (x * y) * (1 - cos) - z * sin;
        out.a02 = (x * z) * (1 - cos) + y * sin;
        out.a10 = (x * y) * (1 - cos) + z * sin;
        out.a11 = cos + (y * y) * (1 - cos);
        out.a12 = (y * z) * (1 - cos) - x * sin;
        out.a20 = (z * x) * (1 - cos) - y * sin;
        out.a21 = (z * y) * (1 - cos) + x * sin;
        out.a22 = cos + (z * z) * (1 - cos);

        return out;
    }

    constexpr static mat4 scale(vec3 s)
    {
        mat4 out;
        out.a00 = s.x;
        out.a11 = s.y;
        out.a22 = s.z;
        return out;
    }

    constexpr static mat4 ortho(float left,
                                float right,
                                float bottom,
                                float top,
                                float near,
                                float far)
    {
        mat4 out;
        out.a00 = 2 / (right - left);
        out.a11 = 2 / (top - bottom);
        out.a22 = -2 / (far - near);

        out.a03 = -(right + left) / (right - left);
        out.a13 = -(top + bottom) / (top - bottom);
        out.a23 = -(far + near) / (far - near);
        return out;
    }

    constexpr gk::vec4 row0() const { return {a00, a01, a02, a03}; }
    constexpr gk::vec4 row1() const { return {a10, a11, a12, a13}; }
    constexpr gk::vec4 row2() const { return {a20, a21, a22, a23}; }
    constexpr gk::vec4 row3() const { return {a30, a31, a32, a33}; }
};

constexpr mat4 IDENTITY;

static_assert(std::is_standard_layout_v<vec2>);
static_assert(std::is_standard_layout_v<vec3>);
static_assert(std::is_standard_layout_v<vec4>);
static_assert(std::is_standard_layout_v<mat4>);

} // namespace gk

using gk_vec2 = gk::vec2;
using gk_vec3 = gk::vec3;
using gk_vec4 = gk::vec4;
using gk_mat4 = gk::mat4;
