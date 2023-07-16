#include "Shape.h"
#include "Point.h"
#include "ExactDistance.h"
#include "ApproximateDistance.h"

#include <iostream>

int main()
{
  	// Initializatoin 
	Point p1(3.0, 4.0); //point 
  	Point p2(1.0, 1.0); //point
  	                    
	//defining the two strategies
  	DistanceStrategy exact( ExactDistance::Distance);                                   
	DistanceStrategy approx(ApproximateDistance::Distance); 

	// Part B:
  	p1.setStrategy(&exact);
  	std::cout << "Exact & state: " << p1.Distance(p2) << std::endl; // exact & state 
   	// use exact strategy
  	std::cout << "Exact & stateless: " << p1.Distance(p2, exact)
            << std::endl;                             // exact & stateless
  	p1.setStrategy(&approx);
  	std::cout << "Approx & state: " << p1.Distance(p2) << std::endl; // approx & state 

  	std::cout << "Exact Distance stateless: " << p1.Distance(p2, approx) // approx & stateless
            << std::endl;


	//Part C: including a counter variable
  	std::cout << "Exact counter is: " << exact.val_counter() << std::endl; 
            
  	std::cout << "Approx counter is: " << approx.val_counter() << std::endl;
}
