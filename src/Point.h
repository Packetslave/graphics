//
// Created by Brian Landers on 2018-12-25.
//

#ifndef GRAPHICS_POINT_H
#define GRAPHICS_POINT_H

#include "Tuple.h"
#include "Vector3.h"

class Point : public Tuple {
public:
    Point() = default;

    Point(float x, float y, float z) : Tuple(x, y, z, 1.0) {}
};

inline Vector3 operator-(const Point &a, const Point &b) {
    return Vector3(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
}

inline Point operator-(const Point &a, const Vector3 &b) {
    return Point(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
}

#endif //GRAPHICS_POINT_H
