#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
    std::cout << "Point: Default constructor called" << std::endl;
}

Point::Point(const float a, const float b): _x(a), _y(b)
{
    std::cout << "Point: Constructor called" << std::endl;
}

Point::Point(const Point& other)
{
    std::cout << "Point: Copy constructor called" << std::endl;
    *this = other;
}

Point& Point::operator=(const Point& other)
{
    std::cout << "Point: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

Point::~Point()
{
    std::cout << "Point: Destructor called" << std::endl;
}
