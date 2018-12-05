//
// Created by Brian Landers on 2018-12-04.
//

#ifndef GRAPHICS_PPM_H
#define GRAPHICS_PPM_H

#include <string>

#define MAX_INTENSITY 255

class PPM {

public:
    PPM(int width, int height) : width_(width), height_(height) {};
    std::string to_string();

private:
    int width_;
    int height_;
};


#endif //GRAPHICS_PPM_H
