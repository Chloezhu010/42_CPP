#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap: Default constructor called" << std::endl;
}

/* constructor: init with 
    - name
    - hit points 10
    - energy point 10
    - attack damage 0
*/
ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
    std::cout << "ClapTrap: Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{

}

void    ClapTrap::takeDamage(unsigned int amount)
{

}

void    ClapTrap::beRepaired(unsigned int amount)
{

}