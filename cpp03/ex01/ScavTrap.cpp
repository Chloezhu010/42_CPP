#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor called" << std::endl;
}
