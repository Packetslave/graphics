//
// Created by Brian Landers on 2018-12-14.
//

//
// Created by Brian Landers on 2018-12-07.
//

#include "gtest/gtest.h"
#include "../src/Matrix.h"

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

    TEST(Matrix, CreateIdentity) {
        Matrix a({
                         {1, 0, 0, 0},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0},
                         {0, 0, 0, 1}
                 });
        Matrix b = CreateIdentityMatrix(4);
        ASSERT_EQ(a, b);
    }

    TEST(Matrix, MultiplyByIdentity) {
        Matrix a = CreateIdentityMatrix(4);
        Matrix b({
                         {0, 1, 2,  4},
                         {1, 2, 4,  8},
                         {2, 4, 8,  16},
                         {4, 8, 16, 32}
                 });
        Matrix c = b * a;

        ASSERT_EQ(b, c);
    }

    TEST(Matrix, Transpose) {
        Matrix a({
                         {0, 9, 3, 0},
                         {9, 8, 0, 8},
                         {1, 8, 5, 3},
                         {0, 0, 5, 8}
                 });
        Matrix b({
                         {0, 9, 1, 0},
                         {9, 8, 8, 0},
                         {3, 0, 5, 5},
                         {0, 8, 3, 8}
                 });
        Matrix c = a.transpose();
        ASSERT_EQ(b, c);
    }

    TEST(Matrix, TransposeIdentity) {
        Matrix a = CreateIdentityMatrix(4);
        Matrix b = a.transpose();
        ASSERT_EQ(a, b);
    }

    TEST(Matrix, Determinant2x2) {
        Matrix a({
                         {1,  5},
                         {-3, 2},
                 });
        ASSERT_EQ(17, a.determinant());
    }

    TEST(Matrix, Determinant3x3) {
        Matrix a({
                         {1,  2, 6},
                         {-5, 8, -4},
                         {2,  6, 4},
                 });
        ASSERT_EQ(56, a.cofactor(0, 0));
        ASSERT_EQ(12, a.cofactor(0, 1));
        ASSERT_EQ(-46, a.cofactor(0, 2));
        ASSERT_EQ(-196, a.determinant());
    }

    TEST(Matrix, Determinant4x4) {
        Matrix a({
                         {-2, -8, 3,  5},
                         {-3, 1,  7,  3},
                         {1,  2,  -9, 6},
                         {-6, 7,  7,  -9}
                 });
        ASSERT_EQ(690, a.cofactor(0, 0));
        ASSERT_EQ(447, a.cofactor(0, 1));
        ASSERT_EQ(210, a.cofactor(0, 2));
        ASSERT_EQ(51, a.cofactor(0, 3));
        ASSERT_EQ(-4071, a.determinant());
    }

    TEST(Matrix, Submatrix3x3) {
        Matrix a({
                         {1,  5, 0},
                         {-3, 2, 7},
                         {0,  6, -3},
                 });
        Matrix b({
                         {-3, 2},
                         {0,  6},
                 });
        Matrix c = a.submatrix(0, 2);
        ASSERT_EQ(b, c);
    }

    TEST(Matrix, Submatrix4x4) {
        Matrix a({
                         {-6, 1, 1,  6},
                         {-8, 5, 8,  6},
                         {-1, 0, 8,  2},
                         {-7, 1, -1, 1},
                 });
        Matrix b({
                         {-6, 1,  6},
                         {-8, 8,  6},
                         {-7, -1, 1},
                 });
        Matrix c = a.submatrix(2, 1);
        ASSERT_EQ(b, c);
    }

    TEST(Matrix, Minor3x3) {
        Matrix a({
                         {3, 5,  0},
                         {2, -1, -7},
                         {5, -1, 5},
                 });
        Matrix b = a.submatrix(1, 0);
        ASSERT_EQ(25, b.determinant());
        ASSERT_EQ(25, a.minor(1, 0));
    }

    TEST(Matrix, Cofactor) {
        Matrix a({
                         {3, 5,  0},
                         {2, -1, -7},
                         {6, -1, 5},
                 });
        ASSERT_EQ(-12, a.minor(0, 0));
        ASSERT_EQ(-12, a.cofactor(0, 0));
        ASSERT_EQ(25, a.minor(1, 0));
        ASSERT_EQ(-25, a.cofactor(1, 0));
    }

    TEST(Matrix, IsInvertible) {
        Matrix a({
                         {6, 4,  4, 4},
                         {5, 5,  7, 6},
                         {4, -9, 3, -7},
                         {9, 1,  7, -6},
                 });
        ASSERT_EQ(-2120, a.determinant());
        ASSERT_TRUE(a.is_invertible());

        Matrix b({
                         {-4, 2,  -2, -3},
                         {9,  6,  2,  6},
                         {0,  -5, 1,  -5},
                         {0,  0,  0,  0},
                 });
        ASSERT_EQ(0, b.determinant());
        ASSERT_FALSE(b.is_invertible());
    }

    bool matrix_is_near(Matrix a, Matrix b, float abs) {
        for (int row = 0; row < a.size(); ++row) {
            for (int col = 0; col < a.size(); ++col) {
                if (std::abs(a.get(row, col) - b.get(row, col)) > abs) {
                    return false;
                }
            }
        }
        return true;
    }

    TEST(Matrix, Inverse1) {
        Matrix a({
                         {-5, 2,  6,  -8},
                         {1,  -5, 1,  8},
                         {7,  7,  -6, -7},
                         {1,  -3, 7,  4},
                 });
        Matrix b({
                         {0.21805,  0.45113,  0.24060,  -0.04511},
                         {-0.80827, -1.45677, -0.44361, 0.52068},
                         {-0.07895, -0.22368, -0.05263, 0.19737},
                         {-0.52256, -0.81391, -0.30075, 0.30639},
                 });
        ASSERT_EQ(532.0, a.determinant());
        ASSERT_EQ(-160.0, a.cofactor(2, 3));
        ASSERT_NEAR(-160.0 / 532.0, b.get(3, 2), 0.00001);
        ASSERT_EQ(105.0, a.cofactor(3, 2));
        ASSERT_NEAR(105.0 / 532.0, b.get(2, 3), 0.00001);
        ASSERT_TRUE(matrix_is_near(b, a.inverse(), 0.00001));
    }

    TEST(Matrix, Inverse2) {
        Matrix a({
                         {8,  -5, 9,  2},
                         {7,  5,  6,  1},
                         {-6, 0,  9,  6},
                         {-3, 0,  -9, -4},
                 });
        Matrix b({
                         {-0.15385, -0.15385, -0.28205, -0.53846},
                         {-0.07692, 0.12308,  0.02564,  0.03077},
                         {0.35897,  0.35897,  0.43590,  0.92308},
                         {-0.69231, -0.69231, -0.76923, -1.92308},
                 });
        ASSERT_TRUE(matrix_is_near(b, a.inverse(), 0.00001));
    }

    TEST(Matrix, Inverse3) {
        Matrix a({
                         {9,  3,  0,  9},
                         {-5, -2, -6, -3},
                         {-4, 9,  6,  4},
                         {-7, 6,  6,  2},
                 });
        Matrix b({
                         {-0.04074, -0.07778, 0.14444,  -0.22222},
                         {-0.07778, 0.03333,  0.36667,  -0.33333},
                         {-0.02901, -0.14630, -0.10926, 0.12963},
                         {0.17778,  0.06667,  -0.26667, 0.33333},
                 });
        ASSERT_TRUE(matrix_is_near(b, a.inverse(), 0.00001));
    }

    TEST(Matrix, MultiplyByInverse) {
        Matrix a({
                         {3,  -9, 7,  3},
                         {3,  -8, 2,  -9},
                         {-4, 4,  4,  1},
                         {-6, 5,  -1, 1},
                 });
        Matrix b({
                         {8, 2,  2, 2},
                         {3, -1, 7, 0},
                         {7, 0,  5, 4},
                         {6, -2, 0, 5},
                 });
        Matrix c = a * b;
        Matrix d = c * b.inverse();
        ASSERT_TRUE(matrix_is_near(d, a, 0.00001));
    }
}