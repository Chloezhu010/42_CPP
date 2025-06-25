#include "Logging.hpp"

/* default constructor */
Logging::Logging()
{
    std::cout << "Logging: Default constructor called" << std::endl;
}

/* copy constructor */
Logging::Logging(const Logging& other)
{
    std::cout << "Logging: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Logging& Logging::operator=(const Logging& other)
{
    std::cout << "Logging: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
Logging::~Logging()
{
    std::cout << "Logging: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

