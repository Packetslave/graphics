//
// Created by Brian Landers on 2018-12-15.
//

#ifndef GRAPHICS_TUPLE_H
#define GRAPHICS_TUPLE_H


class Tuple {
public:
    Tuple() = default;

    Tuple(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) {}

    float x() const { return x_; }

    float y() const { return y_; }

    float z() const { return z_; }

    float w() const { return w_; }

private:
    float x_, y_, z_, w_;
};

inline bool operator==(const Tuple &a, const Tuple &b) {
    return a.x() == b.x() && a.y() == b.y() && a.z() == b.z() && a.w() == b.w();
}

inline Tuple operator+(const Tuple &a, const Tuple &b) {
    return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z(), a.w() + b.w()};
}

inline Tuple operator-(const Tuple &a, const Tuple &b) {
    return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z(), a.w() - b.w()};
}

inline Tuple operator-(const Tuple &a) {
    return {0 - a.x(), 0 - a.y(), 0 - a.z(), 0 - a.w()};
}

inline Tuple operator*(const Tuple &a, const float b) {
    return {a.x() * b, a.y() * b, a.z() * b, a.w() * b};
}

inline Tuple operator/(const Tuple &a, const float b) {
    return {a.x() / b, a.y() / b, a.z() / b, a.w() / b};
}

#endif //GRAPHICS_TUPLE_H
