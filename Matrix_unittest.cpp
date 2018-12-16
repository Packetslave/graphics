//
// Created by Brian Landers on 2018-12-14.
//

//
// Created by Brian Landers on 2018-12-07.
//

#include "gtest/gtest.h"
#include "Matrix.h"

namespace {
    TEST(Matrix, Create4x4) {
        Matrix m(
                {
                        {1,    2,    3,    4},
                        {5.5,  6.5,  7.5,  8.5},
                        {9,    10,   11,   12},
                        {13.5, 14.5, 15.5, 16.5}
                });
        ASSERT_EQ(m.get(0, 0), 1);
        ASSERT_EQ(m.get(0, 3), 4);
        ASSERT_EQ(m.get(1, 0), 5.5);
        ASSERT_EQ(m.get(1, 2), 7.5);
        ASSERT_EQ(m.get(2, 2), 11);
        ASSERT_EQ(m.get(3, 0), 13.5);
        ASSERT_EQ(m.get(3, 2), 15.5);
    }

    TEST(Matrix, Create2x2) {
        Matrix m({
                         {-3, 5},
                         {1,  -2}
                 }
        );
        ASSERT_EQ(m.get(0, 0), -3);
        ASSERT_EQ(m.get(0, 1), 5);
        ASSERT_EQ(m.get(1, 0), 1);
        ASSERT_EQ(m.get(1, 1), -2);
    }

    TEST(Matrix, Create3x3) {
        Matrix m({
                         {-3, 5,  0},
                         {1,  -2, -7},
                         {0,  1,  1}
                 });
        ASSERT_EQ(m.get(0, 0), -3);
        ASSERT_EQ(m.get(1, 1), -2);
        ASSERT_EQ(m.get(2, 2), 1);
    }

    TEST(Matrix, Equality) {
        Matrix a({
                         {1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 8, 7, 6},
                         {5, 4, 3, 2}
                 });
        Matrix b({
                         {1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 8, 7, 6},
                         {5, 4, 3, 2}
                 });
        ASSERT_EQ(a, b);

    }

    TEST(Matrix, Inequality) {
        Matrix a({
                         {1, 2, 3,  4},
                         {5, 6, 7,  8},
                         {9, 8, 37, 6},
                         {5, 4, 3,  2}
                 });
        Matrix b({
                         {1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 8, 7, 6},
                         {5, 4, 3, 2}
                 });
        ASSERT_NE(a, b);
    }

    TEST(Matrix, Multiply) {
        Matrix a({
                         {1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 8, 7, 6},
                         {5, 4, 3, 2}
                 });
        Matrix b({
                         {-2, 1, 2, 3},
                         {3,  2, 1, -1},
                         {4,  3, 6, 5},
                         {1,  2, 7, 8}
                 });
        Matrix c({
                         {20, 22, 50,  48},
                         {44, 54, 114, 108},
                         {40, 58, 110, 102},
                         {16, 26, 46,  42}
                 });
        Matrix d = a * b;
        ASSERT_EQ(d, c);
    }

    TEST(Matrix, MultiplyByTuple) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, CreateIdentity) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, MultiplyByIdentity) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, MultiplyIdentityByTuple) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Transpose) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, TransposeIdentity) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Determinant2x2) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Determinant3x3) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Determinant4x4) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Submatrix3x3) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Submatrix4x4) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Minor) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Cofactor) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, IsInvertible) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Inverse1) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, Inverse2) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }

    TEST(Matrix, MultiplyByInverse) {
        FAIL() << "Unimplemented";  // FIXME: implement this
    }
}