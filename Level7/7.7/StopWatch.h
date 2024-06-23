#pragma once
#include <chrono>

class StopWatch
{
public:
    StopWatch(): start(), end(), ON(false){};

    void StartStopWatch(){
      if (!ON) { // check if it's not ON
            start = std::chrono::high_resolution_clock::now();
            ON = true;
        }
    }

    void StopStopWatch(){
       if (ON) { // check if it is ON
        end = std::chrono::high_resolution_clock::now();
        ON = false;
    }}

    void Reset(){start = {}; end = {};ON = false;}; // oneliner
    
    double GetTime() const{
         if (ON) { // get time even when it's still ON
            auto now = std::chrono::high_resolution_clock::now();
            return std::chrono::duration<double>(now - start).count();
        } else {
            return std::chrono::duration<double>(end - start).count();
        }
    }
private:
    StopWatch(const StopWatch &) = default;
    StopWatch & operator=(const StopWatch &) = default; // implementing constructo as default(?)
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
    bool ON;
};
