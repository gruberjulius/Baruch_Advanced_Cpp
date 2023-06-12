#include<iostream>

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

class C1
{
private:
    //double* d; OLD WAY
    std::shared_ptr<double> d;
public:
    C1(std::shared_ptr<double> value) : d(value) {}
    virtual ~C1() { std::cout <<"\nC1 destructor\n";
        std::cout << d.use_count();
    }
    void print() const { std::cout <<"Value "<<*d; }
};


class C2
{
private:
    //double* d; OLD WAY
    std::shared_ptr<double> d;
public:
    C2(std::shared_ptr<double> value) : d(value) {}
    virtual ~C2() { std::cout <<"\nC2 destructor\n";
        std::cout << d.use_count();
    }
    void print() const { std::cout <<"Value "<<*d; }
};


class C1_point
{
private:
    //double* d; OLD WAY
    std::shared_ptr<Point> d;
public:
    C1_point(std::shared_ptr<Point> value) : d(value) {}
    virtual ~C1_point() { std::cout <<"\nC1 point destructor\n";
        std::cout << d.use_count();
    }
};


class C2_point
{
private:
    //double* d; OLD WAY
    std::shared_ptr<Point> d;
public:
    C2_point(std::shared_ptr<Point> value) : d(value) {}
    virtual ~C2_point() { std::cout <<"\nC2 destructor\n";
        std::cout << d.use_count();
    }
};


template<typename T>
using Sptr = std::shared_ptr<T>;

int main(){
    Sptr<double> x = std::make_shared<double>(1.0);
    {
        std::cout << x.use_count();
        C1 c1(x);
        std::cout << x.use_count();
        C2 c2 (x);
        std::cout << x.use_count();
    }
    std::cout << x.use_count();
    x.reset();
    std::cout << x.use_count();

    //b.

    Sptr<Point> p = std::make_shared<Point>(3.0, 3.0);

    {
        std::cout << p.use_count();
        C1_point c1(p);
        std::cout << p.use_count();
        C2_point c2 (p);
        std::cout << p.use_count();
    }
    std::cout << p.use_count();
    p.reset();
    std::cout << p.use_count();
    
    //d. 
    
    // testing features:
    std::shared_ptr<double> val1(new double(1.0));
    // assigning
    std::shared_ptr<double> sp1 = val1;
    // copying
    std::shared_ptr<double> sp2 = std::make_shared<double>(*sp1);
    // comparing for equality
    if (sp1 == sp2) {
        std::cout << "sp1 and sp2 are the same" << std::endl;
    }else{
        std::cout << "sp1 and sp2 are not the same" << std::endl;
    }

    // transfering ownership from sp1 to sp2
    sp2 = std::move(val1);
    std::cout << "Pointers count after ownership transfer: " << val1.use_count() << std::endl;

    //determining if a shared_ptr is the only pointer to a resource
    std::shared_ptr<double> sp3(new double(1.0));
    std::cout << "is sp1 unique: " << (sp1.use_count() > 1) << std::endl;
    std::cout << "is sp2 unique: " << (sp2.use_count() > 1) << std::endl;
    std::cout << "is sp3 unique: " << (sp3.use_count() > 1) << std::endl;

    //Swap operations
    std::cout << "Pointers count before swap: " << sp1.use_count() << std::endl;
    sp1.swap(sp2);
    std::cout << "Pointers count after swap: " << sp1.use_count() << std::endl;

    // giving up ownership and reinitialise the shared pointer as being empty.
    sp1.reset();
    std::cout << "Pointers count after reset: " << sp1.use_count() << std::endl;

    std::cout << "Pointers count before: " << val1.use_count() << std::endl;

    return 0;
}

