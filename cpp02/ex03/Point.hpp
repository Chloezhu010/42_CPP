#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        /* constructor */
        Point();                              // Default constructor
        Point(const float a, const float b);
        Point(const Point& other);            // Copy constructor
        
        /* operator */
        Point& operator=(const Point& other); // Copy assignment
        
        /* desturctor */
        ~Point();                             // Destructor
};

#endif
