#include "Cat.hpp"

/* default constructor */
Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

/* destructor */
Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
}

/* member functions */
void    Cat::makeSound() const
{
    std::cout << this->type << " meow!🐱\n";
}
