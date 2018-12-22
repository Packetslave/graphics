//
// Created by Brian Landers on 2018-12-19.
//

#ifndef GRAPHICS_TIMER_H
#define GRAPHICS_TIMER_H

#include <chrono>
#include <string>
#include <iostream>

using hrc = std::chrono::high_resolution_clock;

class Timer {
public:
    explicit Timer(std::string name) : name_(name), start_(hrc::now()) {}

    ~Timer() {
        const auto t2 = hrc::now();
        const auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - start_);

        std::cout << std::fixed << std::setprecision(10);
        std::cout << name_ << ": " << time_span.count() << " seconds " << std::endl;
    }

private:
    std::string name_;
    hrc::time_point start_;
};


#endif //GRAPHICS_TIMER_H
