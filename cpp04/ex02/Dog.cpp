#include "Dog.hpp"

/* default constructor */
Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

/* destructor */
Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
}

/* member functions */
void    Dog::makeSound() const
{
    std::cout << this->type << " woof!🐶\n";
}
