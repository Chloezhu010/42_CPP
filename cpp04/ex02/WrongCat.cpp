#include "WrongCat.hpp"

/* default constructor */
WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

/* destructor */
WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

/* member functions */
void    WrongCat::makeSound() const
{
    std::cout << this->type << " wrong meow!❌🐱\n";
}
