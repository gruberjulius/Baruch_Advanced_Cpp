#pragma once

// Part A

// forward delcaration of point class
class Point;

class DistanceStrategy
{
    private:
        std::function<double( const Point& p1, const Point& p2  )> strat_;
        int counter;
public:

    DistanceStrategy(std::function<double( const Point& p1, const Point& p2  )> strat){
        counter = 0;
        strat_ = strat;
    }
	double Distance(const Point& p1, const Point& p2){
        counter++;
        return strat_(p1, p2);
    };

    int val_counter(){
        return counter;
    }
};
