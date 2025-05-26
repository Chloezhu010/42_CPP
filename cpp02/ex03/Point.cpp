#include "Point.hpp"

/* default constructor */
Point::Point(): _x(0), _y(0)
{
    // std::cout << "Point: Default constructor called" << std::endl;
}

/* constructor */
Point::Point(const float a, const float b): _x(a), _y(b)
{
    // std::cout << "Point: Constructor called" << std::endl;
}

/* copy constructor
    - need to use initializer list not assignement
    - as _x, _y are const
*/
Point::Point(const Point& other): _x(other.get_x()), _y(other.get_y())
{
    // std::cout << "Point: Copy constructor called" << std::endl;
}

/* operator= */
Point& Point::operator=(const Point& other)
{
    // std::cout << "Point: Copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

/* destructor */
Point::~Point()
{
    // std::cout << "Point: Destructor called" << std::endl;
}

/* getter */
Fixed Point::get_x(void) const
{
    return (this->_x);
}

/* getter */
Fixed Point::get_y(void) const
{
    return (this->_y);
}

/* helper function to cal cross product */
Fixed   crossProduct(const Point& a, const Point& b, const Point& point)
{
    return (
        (b.get_x() - a.get_x())*(point.get_y() - a.get_y())
        - (b.get_y() - a.get_y())*(point.get_x() - a.get_x())
    );
}

/* helper function to check the sign: pos, neg, zero */
static int  sign(const Fixed& value)
{
    if (value > 0)
        return (1);
    if (value < 0)
        return (-1);
    else
        return (0);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cp1, cp2, cp3;
    int   sign1, sign2, sign3;

    // edge AB, BC, CA with point
    cp1 = crossProduct(a, b, point);
    cp2 = crossProduct(b, c, point);
    cp3 = crossProduct(c, a, point);
    // get sign of the cross products
    sign1 = sign(cp1);
    sign2 = sign(cp2);
    sign3 = sign(cp3);
    // if any sign is 0, point is on edge, return false
    if (sign1 == 0 || sign2 == 0 || sign3 == 0)
        return (false);
    // check if all signs are the same, if yes return true, else false
    return (sign1 == sign2) && (sign2 == sign3);    
}
