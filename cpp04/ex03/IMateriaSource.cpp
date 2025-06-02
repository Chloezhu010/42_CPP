#include "IMateriaSource.hpp"

/* default constructor */
IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource: Default constructor called" << std::endl;
}

/* copy constructor */
IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    std::cout << "IMateriaSource: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    std::cout << "IMateriaSource: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

