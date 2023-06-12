#include<iostream>

//Part D: Unique Ptr Template for 
template<typename T>
using uptr = std::unique_ptr<T>;

class Point{
    private:
    double _x;
    double _y;

public:
    Point(double x, double y): _x(x), _y(y){
        std::cout << "Constructor called" << std::endl;
    }

    void X(double x){_x = x;};
    void Y(double y){_y = y;};
    ~Point(){
        std::cout << "Destructor called" << std::endl;
    }
};

int main(){  // Block with raw pointer lifecycle
    double* d = new double (1.0);
    Point* pt = new Point(1.0, 2.0);// Two-d Point class
	try{
    	// Dereference and call member functions
    	*d = 2.0;
    
    	(*pt).X(3.0);// Modify x coordinate
    	(*pt).Y(3.0);// Modify y coordinate
		throw 1;
    }catch(int e){
		std::cout << "Throe error in memory allocation" << std::endl;
	}	
    pt->X(3.0);
    pt->Y(3.0);
    // Explicitly clean up memory (if you have not forgotten)
    delete d;
    delete pt;
    return 0;
	
	//memory managment now done by unique ptr
	std::unique_ptr<double> d_1 = std::make_unique<double>(1.0);
	std::unique_ptr<Point> pt_1 = std::make_unique<Point>(1.0, 2.0);

	*d_1 = 2;
	(*pt_1).X(3.0);
	(*pt_1).Y(3.0);
	
	//Exercise c
	//two unique pointers to the same pointer	
	std::unique_ptr<double> x= std::make_unique<double>();
	std::unique_ptr<Point> pt_2= std::make_unique<Point>(3.0, 3.0);
	//not working because of unique ptr
	//std::unique_ptr<double> y= x;
	//std::unique_ptr<Point> pt_3= pt_2;
	//transferring ownership with std::move
	std::unique_ptr<double> y = std::move(x); 
	std::unique_ptr<Point> pt_3 = std::move(pt_2); 
	
	uptr<double> x_2 = std::make_unique<double>();
	uptr<double> x_3 = std::move(x_2);	

	uptr<Point> pt_4= std::make_unique<Point>(3.0, 3.0);
	uptr<Point> pt_5= std::move(pt_4);	

	return 0;
}
