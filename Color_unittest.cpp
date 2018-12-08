//
// Created by Brian Landers on 2018-12-07.
//

#include "gtest/gtest.h"
#include "Color.h"

namespace {
    TEST(Color, Add) {
        Color a(3, -2, 5);
        Color b(-2, 3, 1);
        ASSERT_EQ(Color(1, 1, 6), a + b);
    }

    TEST(Color, Subtract) {
        Color a(3, 2, 1);
        Color b(5, 6, 7);
        ASSERT_EQ(Color(-2, -4, -6), a - b);
    }

    TEST(Color, ScalarMultiply1) {
        Color a(1, -2, 3);
        ASSERT_EQ(Color(3.5, -7, 10.5), a * 3.5);
    }
}