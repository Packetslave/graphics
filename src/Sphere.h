//
// Created by Brian Landers on 2019-01-10.
//

#ifndef GRAPHICS_SPHERE_H
#define GRAPHICS_SPHERE_H

#include <optional>
#include <vector>
#include "Intersection.h"
#include "Ray.h"

class Sphere {
public:
    // FIXME: this can be optimized a fair bit
    std::vector<Intersection> intersects(const Ray &r) {
        std::vector<Intersection> out;

        auto sphere_to_ray = r.origin() - Point(0, 0, 0);
        auto a = Dot(r.direction(), r.direction());
        auto b = 2 * Dot(r.direction(), sphere_to_ray);
        auto c = Dot(sphere_to_ray, sphere_to_ray) - 1;
        auto d = (b * b) - (4 * a * c);

        if (d < 0) {
            return out;
        }

        out.emplace_back(Intersection((-b - sqrt(d)) / (2 * a), this));
        out.emplace_back(Intersection((-b + sqrt(d)) / (2 * a), this));
        return out;
    }

  Vector3 normal_at(const Point &p) {
    return (p - Point(0, 0, 0)).normalize();
  }
};

std::optional<Intersection> Hit(const std::vector<Intersection> &v) {
    std::vector<Intersection> sorted = v;
    std::sort(sorted.begin(), sorted.end(), [](auto a, auto b) {
        return a.t() < b.t();
    });
    for (const auto &i : sorted) {
        if (i.t() > 0) {
            return i;
        }
    }
    return {};
}

#endif //GRAPHICS_SPHERE_H
