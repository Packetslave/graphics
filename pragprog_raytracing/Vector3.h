//
// Created by Brian Landers on 2018-12-06.
//

#ifndef GRAPHICS_VECTOR3_H
#define GRAPHICS_VECTOR3_H

#include <cmath>

class Vector3 {
public:
    Vector3() = default;
    Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

    float x() const { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }

    inline float magnitude() {
        return sqrt(x_*x_ + y_*y_ + z_*z_);
    }

    inline Vector3 normalize() {
        float magnitude = this->magnitude();

        return {
            x_ / magnitude,
            y_ / magnitude,
            z_ / magnitude
        };
    }

private:
    float x_, y_, z_;
};

inline bool operator==(const Vector3& a, const Vector3& b) {
    return a.x() == b.x() && a.y() == b.y() && a.z() == b.z();
}

inline Vector3 operator+(const Vector3& a, const Vector3& b) {
    return { a.x() + b.x(), a.y() + b.y(), a.z() + b.z() };
}

inline Vector3 operator-(const Vector3& a, const Vector3& b) {
    return { a.x() - b.x(), a.y() - b.y(), a.z() - b.z() };
}

inline Vector3 operator-(const Vector3& a) {
    return { 0 - a.x(), 0 - a.y(), 0 - a.z() };
}

inline Vector3 operator*(const Vector3& a, const float b) {
    return { a.x() * b, a.y() * b, a.z() * b };
}

inline Vector3 operator/(const Vector3& a, const float b) {
    return { a.x() / b, a.y() / b, a.z() / b };
}

inline float Dot(const Vector3& a, const Vector3& b) {
    return a.x() * b.x() +
           a.y() * b.y() +
           a.z() * b.z();
}

inline Vector3 Cross(const Vector3& a, const Vector3& b) {
    return {
        a.y() * b.z() - a.z() * b.y(),
        a.z() * b.x() - a.x() * b.z(),
        a.x() * b.y() - a.y() * b.x()
    };
}

#endif //GRAPHICS_VECTOR3_H
