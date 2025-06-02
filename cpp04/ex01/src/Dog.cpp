#include "../incl/Dog.hpp"

/* default constructor */
Dog::Dog()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

/* copy constructor */
Dog::Dog(const Dog& other): Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog: Copy constructor called" << std::endl;
}

/* operator overload */
Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

/* destructor */
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog: Destructor called" << std::endl;
}

/* member functions */
void    Dog::makeSound() const
{
    std::cout << this->type << " woof!🐶\n";
}

/* getter */
Brain*  Dog::getBrain() const
{
    return (this->brain);
}