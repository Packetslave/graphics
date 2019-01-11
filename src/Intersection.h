//
// Created by Brian Landers on 2019-01-10.
//

#ifndef GRAPHICS_INTERSECTION_H
#define GRAPHICS_INTERSECTION_H

class Sphere;

class Intersection {
public:
    Intersection(double t, Sphere *o) : t_(t), sphere_(o) {}

    double t() const { return t_; };

    Sphere *object() const { return sphere_; }

private:
    double t_;
    Sphere *sphere_;
};

inline bool operator==(const Intersection &a, const Intersection &b) {
    return a.t() == b.t() && a.object() == b.object();
}

#endif //GRAPHICS_INTERSECTION_H
