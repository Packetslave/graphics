//
// Created by Brian Landers on 2018-12-14.
//

#ifndef GRAPHICS_MATRIX_H
#define GRAPHICS_MATRIX_H

#include <vector>
#include "Vector3.h"

class Matrix {
public:
    explicit Matrix(const size_t size) {  // FIXME: allow non-square matrices
        data_.resize(size);

        for (size_t i = 0; i < size; ++i) {
            data_[i].resize(size);

            for (size_t j = 0; j < size; ++j) {
                data_[i][j] = 0.0;
            }
        }
    }

    explicit Matrix(const std::vector<const std::vector<float>> &values) : Matrix(values.size()) {
        // FIXME: use a better copy function
        size_t size = values.size();

        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                data_[i][j] = values[i][j];
            }
        }
    }

    float get(size_t row, size_t column) const { return data_[row][column]; }

    void set(size_t row, size_t column, float value) { data_[row][column] = value; }

    size_t size() const {
        return data_.size();
    }

    Matrix transpose() const {
        size_t size = data_.size();

        Matrix out(size);
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                out.set(j, i, data_[i][j]);
            }
        }
        return out;
    }

    bool is_invertible() const {
        return this->determinant() != 0;
    }

    float determinant() const {
        size_t size = data_.size();

        if (size == 2) {
            return data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0];
        }
        float out = 0.0;
        for (size_t i = 0; i < size; ++i) {
            out += (data_[0][i] * this->cofactor(0, i));
        }
        return out;
    }

    float minor(size_t row, size_t column) const {
        Matrix sub = this->submatrix(row, column);
        return sub.determinant();
    }

    float cofactor(size_t row, size_t column) const {
        float minor = this->minor(row, column);
        if ((row + column) % 2 == 1) {
            return -minor;
        }
        return minor;
    }

    Matrix inverse() const {
        size_t size = data_.size();
        float det = this->determinant();

        Matrix out(size);
        for (size_t row = 0; row < size; ++row) {
            for (size_t col = 0; col < size; ++col) {
                float c = this->cofactor(row, col);
                out.set(col, row, c / det);
            }
        }
        return out;
    }

    Matrix submatrix(size_t row, size_t column) const {
        size_t size = data_.size();

        Matrix out(size - 1);

        size_t out_r = 0;
        for (size_t r = 0; r < size; ++r) {
            if (r == row) {
                continue;
            }
            size_t out_c = 0;
            for (size_t c = 0; c < size; ++c) {
                if (c == column) {
                    continue;
                }
                out.set(out_r, out_c, data_[r][c]);
                out_c++;
            }
            out_r++;
        }
        return out;
    }

private:
    std::vector<std::vector<float>> data_;
};

inline bool operator==(const Matrix &a, const Matrix &b) {
    size_t size = a.size();
    if (b.size() != size) {
        return false;
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
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
    size_t size = a.size();
    Matrix out(size);

    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size; ++col) {
            float sum = 0.0;
            for (size_t i = 0; i < size; ++i) {
                sum += (a.get(row, i) * b.get(i, col));
            }
            out.set(row, col, sum);
        }
    }
    return out;
}

inline Tuple operator*(const Matrix &a, const Tuple &b) {
    assert(a.size() == 4);  // FIXME: make this generic?

    float out[4];
    for (size_t i = 0; i < 4; ++i) {
        out[i] = a.get(i, 0) * b.x() + a.get(i, 1) * b.y() + a.get(i, 2) * b.z() + a.get(i, 3) * b.w();
    }
    return {
            out[0],
            out[1],
            out[2],
            out[3]
    };
}

Matrix CreateIdentityMatrix(size_t size) {
    Matrix out(size);
    for (size_t i = 0; i < size; ++i) {
        out.set(i, i, 1);
    }
    return out;
}

#endif //GRAPHICS_MATRIX_H
