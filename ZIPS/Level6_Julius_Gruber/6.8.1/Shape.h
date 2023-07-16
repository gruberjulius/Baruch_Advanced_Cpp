#pragma once
#include <iostream>
#include <string>

class Shape
{
public:
	Shape() {};  // Default constructor
	Shape(const Shape& shp) {};  // Copy constructor
	Shape& operator=(const Shape& shp) {}; // Assignment operator 

protected:
	// pure virtual to print shape name 
	virtual std::string print() const { return ""; };

	//friend class to print the shape	
	friend std::ostream& operator<<(std::ostream& out, const Shape& s) {
		return (out << s.print() << " ");
	}


};

