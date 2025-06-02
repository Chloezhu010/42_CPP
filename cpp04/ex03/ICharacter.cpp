#include "ICharacter.hpp"

/* default constructor */
ICharacter::ICharacter()
{
    std::cout << "ICharacter: Default constructor called" << std::endl;
}

/* copy constructor */
ICharacter::ICharacter(const ICharacter& other)
{
    std::cout << "ICharacter: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
ICharacter& ICharacter::operator=(const ICharacter& other)
{
    std::cout << "ICharacter: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
ICharacter::~ICharacter()
{
    std::cout << "ICharacter: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

