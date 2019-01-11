//
// Created by Brian Landers on 2019-01-10.
//

#ifndef GRAPHICS_RAY_H
#define GRAPHICS_RAY_H

#include "Point.h"
#include "Vector3.h"

class Ray {
public:
    Ray(const Point origin, const Vector3 direction) : origin_(origin), direction_(direction) {}

    Point origin() const { return origin_; }

    Vector3 direction() const { return direction_; }

    Point position(const float distance) const {
        return static_cast<Point>(origin_ + (direction_ * distance));
    }

private:
    Point origin_;
    Vector3 direction_;
};


#endif //GRAPHICS_RAY_H
