//
// Created by Brian Landers on 2018-12-07.
//

#include "gtest/gtest.h"
#include "../src/Canvas.h"

namespace {
    TEST(Canvas, SetGet) {
        Canvas c(100, 100);
        ASSERT_EQ(Color(0, 0, 0), c.get(50, 50));

        c.set(50, 50, Color(100, 200, 250));
        ASSERT_EQ(Color(100, 200, 250), c.get(50, 50));
    }
}
