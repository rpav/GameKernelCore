#pragma once

#define GK_CORE_CXX_API
#include <cstring>
#include <cmath>
#include <gk/vec.h>

namespace gk {

template<typename T, typename F>
struct GK_CORE_CXX_API tvec2 {
    using element_type = T;
    using float_type = F;

    T x{0}, y{0};

    tvec2() = default;
    tvec2(const tvec2& v) = default;
    tvec2(T x_, T y_) : x(x_), y(y_) { }

    tvec2 operator-() const { return tvec2(-x, -y); }

    tvec2 operator+(tvec2 v) const { return tvec2(x + v.x, y + v.y); }
    tvec2& operator+=(tvec2 v) { x += v.x; y += v.y; return *this; }

    tvec2 operator-(tvec2 v) const { return tvec2(x - v.x, y - v.y); }
    tvec2& operator-=(tvec2 v) { x -= v.x; y -= v.y; return *this; }


    tvec2 operator+(float f) const { return tvec2(x + f, y + f); }
    tvec2& operator+=(float f) { x += f; y += f; return *this; }

    tvec2 operator-(float f) const { return tvec2(x - f, y - f); }
    tvec2& operator-=(float f) { x -= f; y -= f; return *this; }


    tvec2 operator*(float f) const { return tvec2(x * f, y * f); }
    tvec2& operator*=(float f) { x *= f; y *= f; return *this; }

    tvec2 operator*(tvec2 v) const { return tvec2(x*v.x, y*v.y); }
    tvec2& operator*=(tvec2 v) { x *= v.x; y *= v.y; return *this; }

    tvec2 operator/(float f) const { return tvec2(x / f, y / f); }
    tvec2& operator/=(float f) { x /= f; y /= f; return *this; }

    tvec2 operator/(tvec2 v) const { return tvec2(x/v.x, y/v.y); }
    tvec2& operator/=(tvec2 v) const { x /= v.x; y /= v.y; return *this; }

    tvec2& operator=(tvec2 v) { x = v.x; y = v.y; return *this; }

    void set(T x, T y);
    void set(T*);

    inline bool operator==(tvec2 v) const { return (x == v.x && y == v.y); }
    inline bool operator!=(tvec2 v) const { return !(*this == v); }

    // Note: These are simple but not terribly efficient

    // Requires a normalized vector
    F angle(tvec2 v) const { return std::atan2<F>(v.y, v.x) - std::atan2<F>(y, x); }

    F length() const {
        return std::sqrt<F>((x*x) + (y*y));
    }

    tvec2& normalize() {
        F scale = F(1.0) / length();

        x *= scale;
        y *= scale;

        return *this;
    }

    tvec2& rotate(F radians) {
        F c = std::cos<F>(radians);
        F s = std::sin<F>(radians);

        F _x = x*c - y*s;
        F _y = x*s + y*c;

        x = _x;
        y = _y;

        return *this;
    }

    F dot(tvec2 v) const {
        return (x*v.x) + (y*v.y);
    }

    tvec2& floor() {
        x = std::floor(x);
        y = std::floor(y);
        return *this;
    }

    tvec2& ceil() {
        x = std::ceil(x);
        y = std::ceil(y);
        return *this;
    }

    tvec2& trunc() {
        x = std::trunc(x);
        y = std::trunc(y);
        return *this;
    }
};

using vec2 = tvec2<float,float>;
using i16vec2 = tvec2<int16_t, float>;

struct GK_CORE_CXX_API vec3 {
    float x{0}, y{0}, z{0};

    vec3() = default;
    vec3(float x_, float y_, float z_) { x = x_; y = y_; z = z_; }

    vec3 operator+(const vec3 &v) const { return vec3(x + v.x, y + v.y, z + v.z); }
    vec3& operator+=(const vec3 &v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    vec3 operator-(const vec3 &v) const { return vec3(x - v.x, y - v.y, z - v.z); }
    vec3& operator-=(const vec3 &v) {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    void set(float x_, float y_, float z_) { x = x_; y = y_; z = z_; }
    void set(float *f) { x = f[0]; y = f[1]; z = f[2]; }
};

struct GK_CORE_CXX_API vec4 {
    float x{0}, y{0}, z{0}, w{0};

    vec4() = default;
    vec4(float x_, float y_, float z_, float w_) {
        x = x_; y = y_; z = z_; w = w_;
    }

    vec4(gk_vec4 v) { std::memcpy(this, &v, sizeof(vec4)); }

    operator gk_vec4() const {
        gk_vec4 v;
        std::memcpy(&v, this, sizeof(vec4));
        return v;
    }

    vec4 operator+(const vec4 &v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
    vec4& operator+=(const vec4 &v) {
        x += v.x; y += v.y; z += v.z; w += v.w;
        return *this;
    }

    vec4 operator-(const vec4 &v) const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
    vec4& operator-=(const vec4 &v) {
        x -= v.x; y -= v.y; z -= v.z; w -= v.w;
        return *this;
    }

    void set(float x_, float y_, float z_, float w_) {
        x = x_; y = y_; z = z_; w = w_;
    }
    void set(float *f) {
        x = f[0]; y = f[1]; z = f[2]; w = f[3];
    }
};

struct GK_CORE_CXX_API mat4 {
    float a00{1}, a01{0}, a02{0}, a03{0};
    float a10{0}, a11{1}, a12{0}, a13{0};
    float a20{0}, a21{0}, a22{1}, a23{0};
    float a30{0}, a31{0}, a32{0}, a33{1};

    constexpr mat4() = default;

    mat4(const gk_mat4 &m) {
        std::memcpy(this, &m, sizeof(mat4));
    }

    operator gk_mat4() const {
        gk_mat4 m;
        std::memcpy(&m, this, sizeof(mat4));
        return m;
    }

    void set(float *f) {
        a00 = f[0]; a01 = f[1]; a02 = f[2]; a03 = f[3];
        a10 = f[4]; a11 = f[5]; a12 = f[6]; a13 = f[7];
        a20 = f[8]; a21 = f[9]; a22 = f[10]; a23 = f[11];
        a30 = f[12]; a31 = f[13]; a32 = f[14]; a33 = f[15];
    }

#if defined(GK_GLM_CONVERSIONS)
    mat4(const glm::mat4 &m) { std::memcpy(this, &m, sizeof(*this)); }
    operator glm::mat4() const {
        glm::mat4 m;
        std::memcpy(&m, this, sizeof(mat4));
        return m;
    }
#endif
};

#if defined(GK_GLM_CONVERSIONS)
static_assert(sizeof(glm::mat4) == sizeof(mat4))
#endif

constexpr mat4 IDENTITY;


static_assert(std::is_standard_layout_v<vec2>);
static_assert(std::is_standard_layout_v<vec3>);
static_assert(std::is_standard_layout_v<vec4>);
static_assert(std::is_standard_layout_v<mat4>);

} // namespace gk
