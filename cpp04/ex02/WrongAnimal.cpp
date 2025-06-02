#include "WrongAnimal.hpp"

/* default constructor */
WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

/* copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

/* member functions */
void    WrongAnimal::makeSound() const
{
    std::cout << this->type << " makes a wrong sound!❌\n";
}

/* getter */
std::string    WrongAnimal::getType() const
{
    return (this->type);
}
