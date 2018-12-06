//
// Created by Brian Landers on 2018-12-04.
//

#ifndef GRAPHICS_PPM_H
#define GRAPHICS_PPM_H

#include <string>
#include <vector>
#include "vec3.h"

// FIXME: make this a real constant
#define MAX_INTENSITY 255

class PPM {

public:
    PPM(int width, int height) : width_(width), height_(height) {
        data_ = std::make_unique<std::vector<vec3>>(width * height);
    };

    void write_to_file(std::string filename) const;

private:
    int width_;
    int height_;
    std::unique_ptr<std::vector<vec3>> data_;
};


#endif //GRAPHICS_PPM_H
