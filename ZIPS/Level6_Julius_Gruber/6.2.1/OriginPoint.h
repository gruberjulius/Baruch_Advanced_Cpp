#include "Point.h"
#include "Singleton.h"

// Part A: 

class Point;

// just made a very simple derived class with default constructor, copy constructor & assignment operator
class OriginPoint : public Singleton<Point> {
 public:

  OriginPoint(){};  // default constructor

  OriginPoint(const OriginPoint& source) = delete;  // copy constructor

  OriginPoint& operator=(const OriginPoint& source) =
      delete;  // assignment operator
};

