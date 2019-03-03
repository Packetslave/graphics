//
// Created by Brian Landers on 2018-12-19.
//

#ifndef GRAPHICS_TIMER_H
#define GRAPHICS_TIMER_H

#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

using hrc = std::chrono::high_resolution_clock;

class Timer {
public:
    static const int SECONDS = 1;
    static const int MILLISECONDS = 2;

    explicit Timer(std::string &&name, int resolution = SECONDS) : name_(name), start_(hrc::now()),
                                                                   resolution_(resolution) {}

    ~Timer() {
        const auto t2 = hrc::now();
        const auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - start_);

        auto t = time_span.count();
        std::string s;

        if (resolution_ == SECONDS) {
            s = "seconds";
        } else if (resolution_ == MILLISECONDS) {
            t = time_span.count() * 1000;
            s = "millis";
        };

        std::cout << std::fixed << std::setprecision(10);
        std::cout << name_ << ": " << t << " " << s << std::endl;
    }

private:
    std::string name_;
    hrc::time_point start_;
    int resolution_;
};


#endif //GRAPHICS_TIMER_H
