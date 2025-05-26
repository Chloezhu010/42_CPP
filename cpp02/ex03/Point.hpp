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
        /* getter */
        Fixed   get_x(void) const;
        Fixed   get_y(void) const;
};

/* BSP related functions */
Fixed   crossProduct(const Point& a, const Point& b, const Point& point);
bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
