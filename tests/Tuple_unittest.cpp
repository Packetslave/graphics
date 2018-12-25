//
// Created by Brian Landers on 2018-12-06.
//

#include "gtest/gtest.h"
#include "../src/Tuple.h"

namespace {
    TEST(Tuple, Add) {
        Tuple a(3, -2, 5, 1);
        Tuple b(-2, 3, 1, 0);
        Tuple c = a + b;
        ASSERT_EQ(Tuple(1, 1, 6, 1), c);
    }
}
