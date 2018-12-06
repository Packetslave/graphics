//==================================================================================================
// Written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is distributed
// without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication along
// with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==================================================================================================
//
// Local changes:
//   - use C++ headers instead of legacy C headers
//   - use initializer list for constructor
//   - use individual member vars instead of a list
//   - use brace initializers for return values
//   - use doubles instead of floats where needed to clear lint warnings
//==================================================================================================

#ifndef VEC3H
#define VEC3H

#include <cmath>
#include <cstdlib>
#include <iostream>

class vec3 {


public:
    vec3() : x_(0), y_(0), z_(0) {}

    vec3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

    inline float x() const { return x_; }

    inline float y() const { return y_; }

    inline float z() const { return z_; }

    inline float r() const { return x_; }

    inline float g() const { return y_; }

    inline float b() const { return z_; }

    inline const vec3 &operator+() const { return *this; }

    inline vec3 operator-() const { return {-x_, -y_, -z_}; }

    inline float operator[](int i) const {
        switch (i) {
            case 0:
                return x_;
            case 1:
                return y_;
            case 2:
                return z_;
            default:
                throw std::invalid_argument("must be [0,2]");
        }
    }

    inline float &operator[](int i) {
        switch (i) {
            case 0:
                return x_;
            case 1:
                return y_;
            case 2:
                return z_;
            default:
                throw std::invalid_argument("must be [0,2]");
        }
    };

    inline vec3 &operator+=(const vec3 &v);

    inline vec3 &operator-=(const vec3 &v);

    inline vec3 &operator*=(const vec3 &v);

    inline vec3 &operator/=(const vec3 &v);

    inline vec3 &operator*=(float t);

    inline vec3 &operator/=(float t);

    inline float length() const { return sqrt(x_ * x_ + y_ * y_ + z_ * z_); }

    inline float squared_length() const { return x_ * x_ + y_ * y_ + z_ * z_; }

    inline void make_unit_vector();

    float x_, y_, z_;  // FIXME: this should really be private
};


inline std::istream &operator>>(std::istream &is, vec3 &t) {
    is >> t.x_ >> t.y_ >> t.z_;
    return is;
}

inline std::ostream &operator<<(std::ostream &os, const vec3 &t) {
    os << t.x_ << " " << t.y_ << " " << t.z_;
    return os;
}

inline void vec3::make_unit_vector() {
    double k = 1.0 / sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    x_ *= k;
    y_ *= k;
    z_ *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return {v1.x_ + v2.x_, v1.y_ + v2.y_, v1.z_ + v2.z_};
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return {v1.x_ - v2.x_, v1.y_ - v2.y_, v1.z_ - v2.z_};
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return {v1.x_ * v2.x_, v1.y_ * v2.y_, v1.z_ * v2.z_};
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return {v1.x_ / v2.x_, v1.y_ / v2.y_, v1.z_ / v2.z_};
}

inline vec3 operator*(float t, const vec3 &v) {
    return {t * v.x_, t * v.y_, t * v.z_};
}

inline vec3 operator/(vec3 v, float t) {
    return {v.x_ / t, v.y_ / t, v.z_ / t};
}

inline vec3 operator*(const vec3 &v, float t) {
    return {t * v.x_, t * v.y_, t * v.z_};
}

inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.x_ * v2.x_ + v1.y_ * v2.y_ + v1.z_ * v2.z_;
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return {
            (v1.y_ * v2.z_ - v1.z_ * v2.y_),
            (-(v1.x_ * v2.z_ - v1.z_ * v2.x_)),
            (v1.x_ * v2.y_ - v1.y_ * v2.x_)
    };
}


inline vec3 &vec3::operator+=(const vec3 &v) {
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    return *this;
}

inline vec3 &vec3::operator*=(const vec3 &v) {
    x_ *= v.x_;
    y_ *= v.y_;
    z_ *= v.z_;
    return *this;
}

inline vec3 &vec3::operator/=(const vec3 &v) {
    x_ /= v.x_;
    y_ /= v.y_;
    z_ /= v.z_;
    return *this;
}

inline vec3 &vec3::operator-=(const vec3 &v) {
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;
    return *this;
}

inline vec3 &vec3::operator*=(const float t) {
    x_ *= t;
    y_ *= t;
    z_ *= t;
    return *this;
}

inline vec3 &vec3::operator/=(const float t) {
    double k = 1.0 / t;

    x_ *= k;
    y_ *= k;
    z_ *= k;
    return *this;
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif