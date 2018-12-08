//
// Created by Brian Landers on 2018-12-07.
//

#ifndef GRAPHICS_COLOR_H
#define GRAPHICS_COLOR_H


class Color {
public:
    Color(float r, float g, float b) : r_(r), g_(g), b_(b) {}

    inline float r() const { return r_; };
    inline float g() const { return g_; };
    inline float b() const { return b_; };

private:
    float r_;
    float g_;
    float b_;
};

inline bool operator==(const Color& a, const Color& b) {
    return a.r() == b.r() && a.g() == b.g() && a.b() == b.b();
}

inline Color operator+(const Color& a, const Color& b) {
    return { a.r() + b.r(), a.g() + b.g(), a.b() + b.b() };
}

inline Color operator-(const Color& a, const Color& b) {
    return { a.r() - b.r(), a.g() - b.g(), a.b() - b.b() };
}

inline Color operator*(const Color& a, const float b) {
    return { a.r() * b, a.g() * b, a.b() * b };
}

// Hadamard / Schur product
inline Color operator*(const Color& a, const Color& b) {
    return { a.r() * b.r(), a.g() * b.g(), a.b() * b.b() };
}
#endif //GRAPHICS_COLOR_H
