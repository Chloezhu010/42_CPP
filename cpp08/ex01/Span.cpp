#include "Span.hpp"

/* default constructor */
Span::Span()
{
    std::cout << "Span: Default constructor called" << std::endl;
}

/* copy constructor */
Span::Span(const Span& other)
{
    std::cout << "Span: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Span& Span::operator=(const Span& other)
{
    std::cout << "Span: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
Span::~Span()
{
    std::cout << "Span: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

