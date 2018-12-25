//
// Created by Brian Landers on 2018-12-06.
//

#include "gtest/gtest.h"
#include "../src/Point.h"

namespace {
    TEST(Point, Subtract) {
        Point a(3, 2, 1);
        Point b(5, 6, 7);
        Vector3 c = a - b;
        ASSERT_EQ(Vector3(-2, -4, -6), c);
    }

    TEST(Point, SubtractVector) {
        Point a(3, 2, 1);
        Vector3 b(5, 6, 7);
        Point c = a - b;
        ASSERT_EQ(Point(-2, -4, -6), c);
    }
}
