//
// Created by Brian Landers on 2018-12-04.
//

#include "PPM.h"
#include "absl/strings/str_format.h"

std::string PPM::to_string() {
    return absl::StrFormat("%i %i\n%i\n", width_, height_, MAX_INTENSITY);
}
