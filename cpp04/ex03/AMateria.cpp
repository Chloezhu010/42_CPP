#include "AMateria.hpp"

/* default constructor */
AMateria::AMateria()
{
    std::cout << "AMateria: Default constructor called" << std::endl;
}

/* copy constructor */
AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
AMateria::~AMateria()
{
    std::cout << "AMateria: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

