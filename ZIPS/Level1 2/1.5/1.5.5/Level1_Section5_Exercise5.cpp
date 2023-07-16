#include <iostream>
#include<tuple>
#include<functional>
#include <string>
#include <memory>

// Forward declaring Class 
class Shape;
class IODevice;
class IODeviceA;
class Circle;
class Line;
class Rectangle;


class IODevice
{
// Interface for displaying CAD objects
public:
    virtual void operator << (const Circle& c) = 0;
    virtual void operator << (const Line& c) = 0;
    virtual void operator << (const Rectangle& c) = 0;
};

// Class hierarchy
class Shape
{
public:
    virtual void display(IODevice& ioDevice) const = 0;
};

// Derived class circle 
class Circle: public Shape
{
public: 
    int center;
    int rad; 
    // default constructor 
    Circle() { center = 0; rad = 1; };

    // constructor 
    Circle(int c, int r) { center = c; rad = r; };

    // display 
    using Shape::display; 
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
};

// Derived class line 
class Line : public Shape
{
public: 
    int center; 
    int len; 
    
    // default constructor 
    Line() { center = 0; len = 2; };

    // constructor 
    Line(int c, int l) : center(c), len(l) {}; 

    // display 
    using Shape::display;
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
};

// Derived class rectangle 
class Rectangle : public Shape
{
public: 
    int width; 
    int height;
    // default constructor
    Rectangle() { width = 2; height = 3; };

    // constructor 
    Rectangle(int width, int height)
    {
        width = width;
        height = height;
    }
    
    // display 
    using Shape::display;
    void display(IODevice& ioDevice) const override { ioDevice << *this; };
};

class IODeviceA : public IODevice
{
    // interface for displaying CAD objects 
public: 

    // Part A: displaying CAD shape 
    using IODevice::operator<<;
    void operator << (const Circle& c)
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << c.center << " and Radius: " << c.rad << std::endl;
    };

    void operator << (const Line& l)
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Center: " << l.center << " and Length " << l.len << std::endl;
    };

    void operator << (const Rectangle& r)
    {
        std::cout << "IODeviceA is on." << std::endl;
        std::cout << "Width: " << r.width<< " and Height: " << r.height << std::endl;
    };

};

class IODeviceB : public IODevice
{
    // interface for displaying CAD objects 
public:

    void operator << (const Circle& c) override
    {
        std::cout << "IODeviceB is on." << std::endl;
        std::cout << "Center: " << c.center << " and Radius: " << c.rad << std::endl;
    };


    void operator << (const Line& l) override
    {
        std::cout << "IODeviceB is on." << std::endl;
        std::cout << "Center: " << l.center << " and Length: " << l.len << std::endl;
    };

    void operator<<(const Rectangle& r) override
    {
        std::cout << "IODeviceB is on." << std::endl;
        std::cout << "Width: " << r.width << " and Height: " << r.height << std::endl;
    };
};

// the builder creates part of the complex object each time it is called and maintains 
// all intermediate state. When product is finished, the client retrieves the result 
// from the builder 

using shape_pointer = std::shared_ptr<Shape>;
using IO_device_pointer = std::shared_ptr<IODevice>;

class builder
{    
     // hook function that derived classes must implement
     virtual shape_pointer getShape() = 0;
     virtual IO_device_pointer getIODevice() = 0;
     virtual std::tuple<shape_pointer, IO_device_pointer> getProduct() = 0;
};

// builder 1: combines Circle and IODevice A 
class builder_1 : public builder
{
public:
    // Necessary parameters for shape / IODevice
    shape_pointer getShape() {
        std::shared_ptr<Circle> mys(new Circle);
        return mys;
    }
    
    IO_device_pointer getIODevice() {
        std::unique_ptr<IODeviceA> myc(new IODeviceA);
        return myc;
    }

    std::tuple<shape_pointer, IO_device_pointer> getProduct() {
        std::tuple<shape_pointer, IO_device_pointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// builder 2 : Circle and IODevice B
class builder_2 : public builder
{
    // A builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    shape_pointer getShape() {
        std::shared_ptr<Circle> mys(new Circle);
        return mys;
    }

    IO_device_pointer getIODevice() {
        std::unique_ptr<IODeviceB> myc(new IODeviceB);
        return myc;
    }

    std::tuple<shape_pointer, IO_device_pointer> getProduct() {
        std::tuple<shape_pointer, IO_device_pointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// builder 3 : Line and IODevice A 
class builder_3 : public builder
{
    // A builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    shape_pointer getShape() {
        std::shared_ptr<Line> mys(new Line);
        return mys;
    }

    IO_device_pointer getIODevice() {
        std::unique_ptr<IODeviceA> myc(new IODeviceA);
        return myc;
    }

    std::tuple<shape_pointer, IO_device_pointer> getProduct() {
        std::tuple<shape_pointer, IO_device_pointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// builder 4 : Line and IODevice B
class builder_4 : public builder
{
    // A builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    shape_pointer getShape() {
        std::shared_ptr<Line> mys(new Line);
        return mys;
    }

    IO_device_pointer getIODevice() {
        std::unique_ptr<IODeviceB> myc(new IODeviceB);
        return myc;
    }

    std::tuple<shape_pointer, IO_device_pointer> getProduct() {
        std::tuple<shape_pointer, IO_device_pointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// builder 5: Rectangle and IODevice A
class builder_5 : public builder
{
    // A builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    shape_pointer getShape() {
        std::shared_ptr<Rectangle> mys(new Rectangle);
        return mys;
    }

    IO_device_pointer getIODevice() {
        std::unique_ptr<IODeviceA> myc(new IODeviceA);
        return myc;
    }

    std::tuple<shape_pointer, IO_device_pointer> getProduct() {
        std::tuple<shape_pointer, IO_device_pointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};

// builder 6 : Rectangle and IODevice B
class builder_6 : public builder
{
    // A builder hierarchy that builds shapes and io devices 

public:
    // Necessary parameters for shape / IODevice
    shape_pointer getShape() {
        std::shared_ptr<Rectangle> mys(new Rectangle);
        return mys;
    }

    IO_device_pointer getIODevice() {
        std::unique_ptr<IODeviceB> myc(new IODeviceB);
        return myc;
    }

    std::tuple<shape_pointer, IO_device_pointer> getProduct() {
        std::tuple<shape_pointer, IO_device_pointer> ptr = std::make_tuple(getShape(), getIODevice());
        return ptr;
    };

};



int main(){
        // Builder 1:  Circle + IODeviceA
    builder_1 b1; // deligating a 2D cicle 
    shape_pointer circle_B1 = std::get<0>(b1.getProduct());
    IO_device_pointer iodA_B1 = std::get<1>(b1.getProduct());
    (*circle_B1).display(*iodA_B1);

    // Builder 2:  Circle + IODeviceB
    builder_2 b2;
    shape_pointer circle_B2 = std::get<0>(b2.getProduct());
    IO_device_pointer iodB_B2 = std::get<1>(b2.getProduct());
    (*circle_B2).display(*iodB_B2);


    // Builder 3: Line + IODeviceA 
    builder_3 b3; 
    shape_pointer circle_B3 = std::get<0>(b3.getProduct());
    IO_device_pointer iodA_B3 = std::get<1>(b3.getProduct());
    (*circle_B3).display(*iodA_B3);

    // Builder 4: Line + IODeviceB
    builder_4 b4;  
    shape_pointer circle_B4 = std::get<0>(b4.getProduct());
    IO_device_pointer iodA_B4 = std::get<1>(b4.getProduct());
    (*circle_B4).display(*iodA_B4);

    // Builder 5: Rectangle + IODeviceA 
    builder_5 b5;
    shape_pointer circle_B5 = std::get<0>(b5.getProduct());
    IO_device_pointer iodA_B5 = std::get<1>(b5.getProduct());
    (*circle_B5).display(*iodA_B5);

    // Builder 6: Rectangle + IODeviceB 
    builder_6 b6;
    shape_pointer circle_B6 = std::get<0>(b6.getProduct());
    IO_device_pointer iodA_B6 = std::get<1>(b6.getProduct());
    (*circle_B6).display(*iodA_B6);
    return 0;
}
