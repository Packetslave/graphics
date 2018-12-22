//
// Created by Brian Landers on 2018-12-06.
//

#include "gtest/gtest.h"
#include "../src/Vector3.h"

namespace {
    TEST(Vector3, Add) {
        Vector3 a(3, -2, 5);
        Vector3 b(-2, 3, 1);
        ASSERT_EQ(Vector3(1, 1, 6), a + b);
    }

    TEST(Vector3, Subtract) {
        Vector3 a(3, 2, 1);
        Vector3 b(5, 6, 7);
        ASSERT_EQ(Vector3(-2, -4, -6), a - b);
    }

    TEST(Vector3, Negate) {
        Vector3 a(1, -2, 3);
        ASSERT_EQ(Vector3(-1, 2, -3), -a);
    }

    TEST(Vector3, ScalarMultiply1) {
        Vector3 a(1, -2, 3);
        ASSERT_EQ(Vector3(3.5, -7, 10.5), a * 3.5);
    }

    TEST(Vector3, ScalarMultiply2) {
        Vector3 a(1, -2, 3);
        ASSERT_EQ(Vector3(0.5, -1, 1.5), a * 0.5);
    }

    TEST(Vector3, ScalarDivide) {
        Vector3 a(1, -2, 3);
        ASSERT_EQ(Vector3(0.5, -1, 1.5), a / 2);
    }

    TEST(Vector3, Normalize1) {
        Vector3 a(4, 0, 0);
        ASSERT_EQ(Vector3(1, 0, 0), a.normalize());
    }

    TEST(Vector3, Normalize2) {
        Vector3 a(1, 2, 3);
        auto b = a.normalize();
        ASSERT_NEAR(0.26726, b.x(), 0.00001);
        ASSERT_NEAR(0.53452, b.y(), 0.00001);
        ASSERT_NEAR(0.80178, b.z(), 0.00001);
    }

    TEST(Vector3, Normalize3) {
        Vector3 a(1, 2, 3);
        auto b = a.normalize();
        ASSERT_NEAR(1.0, b.magnitude(), 0.00001);
    }

    TEST(Vector3, DotProduct) {
        Vector3 a(1, 2, 3);
        Vector3 b(2, 3, 4);
        ASSERT_EQ(20, Dot(a, b));
    }

    TEST(Vector3Test, CrossProduct) {
        Vector3 a(1, 2, 3);
        Vector3 b(2, 3, 4);
        ASSERT_EQ(Vector3(-1, 2, -1), Cross(a, b));
        ASSERT_EQ(Vector3(1, -2, 1), Cross(b, a));
    }
}