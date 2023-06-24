#pragma once

#include <chrono>

class watch
{
private:
    // timestamps for start and end
    std::chrono::steady_clock::time_point start, end;

    // standard copy constructor
    watch(const watch& copy) {
        this->start = copy.start;
        this->end = copy.end;
    };

    watch& operator=(const watch& copy) {
        watch newWatch(copy);
        return newWatch;
    };

public:
    // default constructor
    watch() {};

    // setting start to now
    void Startwatch() { start = std::chrono::steady_clock::now(); };
    // setting end to now
    void Stopwatch() { end = std::chrono::steady_clock::now(); };

    // we do both at the same time to reset
    void Reset() {
        start = std::chrono::steady_clock::now();
        end = start;
    };

    // simply take the difference between start and end
    double GetTime() const {
        std::chrono::duration<double> time{ end - start };
        return time.count();
    }
};
