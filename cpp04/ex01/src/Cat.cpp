#include "../incl/Cat.hpp"

/* default constructor */
Cat::Cat()
{
    this->brain = new Brain(); // allocate memory on heap
    this->type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

/* copy constructor */
Cat::Cat(const Cat& other): Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat: Copy constructor called" << std::endl;
}
        
/* operator overload */
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain; // cleanup old memory
        brain = new Brain(*other.brain); // deep copy
    }
    return (*this);
}

/* destructor */
Cat::~Cat()
{
    delete brain; // manually free memory
    std::cout << "Cat: Destructor called" << std::endl;
}

/* member functions */
void    Cat::makeSound() const
{
    std::cout << this->type << " meow!🐱\n";
}

/* getter */
Brain*  Cat::getBrain() const
{
    return (this->brain);
}
