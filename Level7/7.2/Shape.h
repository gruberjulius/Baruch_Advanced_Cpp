#pragma once
#include <iostream>
#include <string>

class Shape
{
public:
	Shape() {};  // Default constructor
	Shape(const Shape& shp) {};  // Copy constructor
	Shape& operator=(const Shape& shp) {}; // Assignment operator 

    virtual std::shared_ptr<Shape> Clone() = 0;
protected:
	// pure virtual function to print shape
	virtual std::string print() const = 0;
	
	// friend function to print class (which will be inherited for all derived classes)
	friend std::ostream& operator<<(std::ostream& out, const Shape& s) {
		return (out << s.print());
	}

};

