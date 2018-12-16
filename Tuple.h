//
// Created by Brian Landers on 2018-12-15.
//

#ifndef GRAPHICS_TUPLE_H
#define GRAPHICS_TUPLE_H


class Tuple {
public:
    Tuple() = default;

    Tuple(float x, float y, float z) : x_(x), y_(y), z_(z) {}

    float x() const { return x_; }

    float y() const { return y_; }

    float z() const { return z_; }

private:
    float x_, y_, z_;
};

inline bool operator==(const Tuple &a, const Tuple &b) {
    return a.x() == b.x() && a.y() == b.y() && a.z() == b.z();
}

inline Tuple operator+(const Tuple &a, const Tuple &b) {
    return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z()};
}

inline Tuple operator-(const Tuple &a, const Tuple &b) {
    return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z()};
}

inline Tuple operator-(const Tuple &a) {
    return {0 - a.x(), 0 - a.y(), 0 - a.z()};
}

inline Tuple operator*(const Tuple &a, const float b) {
    return {a.x() * b, a.y() * b, a.z() * b};
}

inline Tuple operator/(const Tuple &a, const float b) {
    return {a.x() / b, a.y() / b, a.z() / b};
}

#endif //GRAPHICS_TUPLE_H
