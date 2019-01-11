//
// Created by Brian Landers on 2019-01-10.
//

#include "gtest/gtest.h"
#include "../src/Point.h"
#include "../src/Ray.h"

namespace {
    TEST(Ray, Create) {
        Point p(1, 2, 3);
        Vector3 v(4, 5, 6);

        Ray r(p, v);
        ASSERT_EQ(p, r.origin());
        ASSERT_EQ(v, r.direction());
    }

    TEST(Ray, ComputePointFromDistance) {
        Point p(2, 3, 4);
        Vector3 v(1, 0, 0);

        Ray r(p, v);
        ASSERT_EQ(Point(2, 3, 4), r.position(0));
        ASSERT_EQ(Point(3, 3, 4), r.position(1));
        ASSERT_EQ(Point(1, 3, 4), r.position(-1));
        ASSERT_EQ(Point(4.5, 3, 4), r.position(2.5));
    }
}
