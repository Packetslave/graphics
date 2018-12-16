//
// Created by Brian Landers on 2018-12-14.
//

#ifndef GRAPHICS_MATRIX_H
#define GRAPHICS_MATRIX_H

#include <vector>
#include "Vector3.h"

class Matrix {
public:
    Matrix(const int size) {  // FIXME: allow non-square matrices
        data_.resize(size);

        for (int i = 0; i < size; ++i) {
            data_[i].resize(size);

            for (int j = 0; j < size; ++j) {
                data_[i][j] = 0.0;
            }
        }
    }

    Matrix(const std::vector<const std::vector<float>> &values) : Matrix(values.size()) {
        // FIXME: use a better copy function
        for (int i = 0; i < values.size(); ++i) {
            for (int j = 0; j < values.size(); ++j) {
                data_[i][j] = values[i][j];
            }
        }
    }

    float get(int row, int column) const { return data_[row][column]; }

    void set(int row, int column, float value) { data_[row][column] = value; }

    int size() const {
        return data_.size();
    }

    Matrix transpose() const {
        return Matrix(1);  // FIXME: implement this
    }

    bool is_invertible() const {
        return this->determinant() != 0;
    }

    int determinant() const {
        return 0;  // FIXME: implement this
    }

    int cofactor(int row, int column) const {
        return 0;  // FIXME: implement this
    }

    Matrix inverse() const {
        return Matrix(1);  // FIXME: implement this
    }

private:
    std::vector<std::vector<float>> data_;
};

inline bool operator==(const Matrix &a, const Matrix &b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (a.get(i, j) != b.get(i, j)) {
                return false;
            }
        }
    }
    return true;
}

inline bool operator!=(const Matrix &a, const Matrix &b) {
    return !(a == b);
}

inline Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix out(a.size());

    for (int row = 0; row < a.size(); ++row) {
        for (int col = 0; col < a.size(); ++col) {
            float sum = 0;
            for (int i = 0; i < a.size(); ++i) {
                sum += (a.get(row, i) * b.get(i, col));
            }
            out.set(row, col, sum);
        }
    }
    return out;
}

inline Matrix operator*(const Matrix &a, const Vector3 &v) {
    // FIXME: implemenmt this
    return Matrix(1);
}

#endif //GRAPHICS_MATRIX_H
