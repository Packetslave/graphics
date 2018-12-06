//==================================================================================================
// Written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is distributed
// without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication along
// with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==================================================================================================
//
// Local changes
// - initializer list for constructor
// - standard variable naming
//
//==================================================================================================

#ifndef RAYH
#define RAYH

#include "vec3.h"

class ray {
public:
    ray() = default;

    ray(const vec3 &a, const vec3 &b) : a_(a), b_(b) {};

    vec3 origin() const { return a_; }

    vec3 direction() const { return b_; }

    vec3 point_at_parameter(float t) const { return a_ + t * b_; }

    vec3 a_;
    vec3 b_;
};

#endif