//
// Created by Brian Landers on 2018-12-06.
//

#ifndef GRAPHICS_VECTOR3_H
#define GRAPHICS_VECTOR3_H

#include <cmath>
#include "Tuple.h"

class Vector3 : public Tuple {
public:
    Vector3() = default;

    Vector3(float x, float y, float z) : Tuple(x, y, z) {}

    inline float magnitude() {
        return sqrt(x() * x() + y() * y() + z() * z());
    }

    inline Vector3 normalize() {
        float magnitude = this->magnitude();

        return {
                x() / magnitude,
                y() / magnitude,
                z() / magnitude
        };
    }
};

inline float Dot(const Vector3 &a, const Vector3 &b) {
    return a.x() * b.x() +
           a.y() * b.y() +
           a.z() * b.z();
}

inline Vector3 Cross(const Vector3 &a, const Vector3 &b) {
    return {
            a.y() * b.z() - a.z() * b.y(),
            a.z() * b.x() - a.x() * b.z(),
            a.x() * b.y() - a.y() * b.x()
    };
}

#endif //GRAPHICS_VECTOR3_H
