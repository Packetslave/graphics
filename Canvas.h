//
// Created by Brian Landers on 2018-12-07.
//

#ifndef GRAPHICS_CANVAS_H
#define GRAPHICS_CANVAS_H

#include "Color.h"
#include <fstream>
#include <vector>
#include "absl/strings/str_format.h"

class Canvas {
public:
    Canvas(int w, int h) : width_(w), height_(h) {
        pixels_ = std::make_unique<std::vector<Color>>(w * h, Color(0, 0, 0));
    }

    inline int width() const { return width_; };

    inline int height() const { return height_; };

    void set(int x, int y, Color c);

    Color get(int x, int y) const;

    std::string dump() const;

    void save(const std::string &filename) const;

private:
    int index_of(int x, int y) const { return width_ * y + x; }

    int width_;
    int height_;
    std::unique_ptr<std::vector<Color>> pixels_;
};

void Canvas::set(int x, int y, Color c) {
    (*pixels_)[index_of(x, y)] = c;
}

Color Canvas::get(int x, int y) const {
    return (*pixels_)[index_of(x, y)];
}

std::string Canvas::dump() const {
    std::string out;
    out.reserve(14 + pixels_->size() * 12); // estimate

    out += absl::StrFormat("P3\n%i %i\n%i\n", width_, height_, 255);

    for (const auto &i : *pixels_) {
        out += absl::StrFormat("%i %i %i\n", int(i.r() * 255.99), int(i.g() * 255.99), int(i.b() * 255.99));
    }
    return out;
}

void Canvas::save(const std::string &filename) const {
    std::ofstream myfile;
    myfile.open(filename);
    myfile << this->dump();
    myfile.close();
}

#endif //GRAPHICS_CANVAS_H
