#include "Ice.hpp"

/* default constructor */
Ice::Ice(): _type("ice")
{
    std::cout << "Ice: Default constructor called" << std::endl;
}

/* copy constructor */
Ice::Ice(const Ice& other)
{
    std::cout << "Ice: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
Ice::~Ice()
{
    std::cout << "Ice: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

