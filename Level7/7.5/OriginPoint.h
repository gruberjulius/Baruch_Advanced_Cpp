#pragma once
#ifndef OriginPoint_hpp
#define OriginPoint_hpp

#include "Point.h"
#include "Singleton.hpp"
#include "Singleton.cpp"

// Part A

class Point;

class OriginPoint : public Singleton<Point> {
 public:

  OriginPoint(){};  // default constructor

  OriginPoint(const OriginPoint& source) = delete;  // copy constructor

  OriginPoint& operator=(const OriginPoint& source) =
      delete;  // assignment operator
};

#endif
