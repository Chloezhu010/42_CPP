#include "Cure.hpp"

/* default constructor */
Cure::Cure()
{
    std::cout << "Cure: Default constructor called" << std::endl;
}

/* copy constructor */
Cure::Cure(const Cure& other)
{
    std::cout << "Cure: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
Cure::~Cure()
{
    std::cout << "Cure: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

