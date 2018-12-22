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

        for (int i = 0; i < size; ++i) {
            data_[i].resize(size);

            for (int j = 0; j < size; ++j) {
                data_[i][j] = 0.0;
            }
        }
    }

    explicit Matrix(const std::vector<const std::vector<float>> &values) : Matrix(values.size()) {
        // FIXME: use a better copy function
        for (int i = 0; i < values.size(); ++i) {
            for (int j = 0; j < values.size(); ++j) {
                data_[i][j] = values[i][j];
            }
        }
    }

    float get(int row, int column) const { return data_[row][column]; }

    void set(int row, int column, float value) { data_[row][column] = value; }

    size_t size() const {
        return data_.size();
    }

    Matrix transpose() const {
        Matrix out(data_.size());
        for (int i = 0; i < data_.size(); ++i) {
            for (int j = 0; j < data_.size(); ++j) {
                out.set(j, i, data_[i][j]);
            }
        }
        return out;
    }

    bool is_invertible() const {
        return this->determinant() != 0;
    }

    float determinant() const {
        if (data_.size() == 2) {
            return data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0];
        }
        float out = 0.0;
        for (int i = 0; i < data_.size(); ++i) {
            out += (data_[0][i] * this->cofactor(0, i));
        }
        return out;
    }

    float minor(int row, int column) const {
        Matrix sub = this->submatrix(row, column);
        return sub.determinant();
    }

    float cofactor(int row, int column) const {
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
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                float c = this->cofactor(row, col);
                out.set(col, row, c / det);
            }
        }
        return out;
    }

    Matrix submatrix(int row, int column) const {
        Matrix out(data_.size() - 1);

        int out_r = 0;
        for (int r = 0; r < data_.size(); ++r) {
            if (r == row) {
                continue;
            }
            int out_c = 0;
            for (int c = 0; c < data_.size(); ++c) {
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

Matrix CreateIdentityMatrix(size_t size) {
    Matrix out(size);
    for (int i = 0; i < size; ++i) {
        out.set(i, i, 1);
    }
    return out;
}

#endif //GRAPHICS_MATRIX_H
