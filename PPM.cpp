//
// Created by Brian Landers on 2018-12-04.
//

#include <fstream>
#include "PPM.h"
#include "absl/strings/str_format.h"

void PPM::write_to_file(const std::string filename) const {
    std::ofstream output;
    output.open(filename);

    // write the header
    output << width_ << " " << height_ << std::endl;
    output << MAX_INTENSITY << std::endl;

    // for converting vec3 to RGB
    double multiplier = (double) MAX_INTENSITY - 0.01;

    for (const auto &val : *data_) {
        output << int(multiplier * val[0]) << " "
               << int(multiplier * val[1]) << " "
               << int(multiplier * val[2]) << std::endl;
    }

    output.close();
}
