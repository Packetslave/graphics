//
// Created by Brian Landers on 2019-01-11.
//

#include "Canvas.h"
#include "Sphere.h"
#include "src/Timer.h"

int main() {
    Timer t("sphere_test1", Timer::MILLISECONDS);

    int canvas_pixels = 100;
    Canvas out(canvas_pixels, canvas_pixels);
    Color red(1, 0, 0);
    Color black(0, 0, 0);

    Sphere s;
    Point origin(0, 0, -5);
    int wall_z = 10;

    float wall_size = 7.0;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2;

    for (int y = 0; y < canvas_pixels - 1; ++y) {
        float world_y = half - pixel_size * y;

        for (int x = 0; x < canvas_pixels - 1; ++x) {
            float world_x = -half + pixel_size * x;

            Point position = Point(world_x, world_y, wall_z);
            Ray r(origin, Vector3(position - origin).normalize());

            auto xs = s.intersects(r);
            if (Hit(xs)) {
                out.set(x, y, red);
            } else {
                out.set(x, y, black);
            }
        }
    }
    out.save("/tmp/sphere_test1.ppm");
}