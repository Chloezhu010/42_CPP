/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:24 by czhu              #+#    #+#             */
/*   Updated: 2025/05/29 14:58:56 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        this->_name = other._name;
        this->_hit_pts = other._hit_pts;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    // check if has hit and energy points
    if (this->_hit_pts > 0 && this->_energy_pts > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " attacks "
            << target << ", causing " << this->_attack_dmg
            << " points of damage!\n";
        this->_energy_pts--;
    }
    // if hit point = 0, print error msg
    else if (this->_hit_pts == 0 && this->_energy_pts > 0)
    {
        std::cout << "ClapTrap: " << this->_name
            << " doesn't have enough hit points\n";
        this->_energy_pts--;
    }
    // if energy point = 0, print error msg
    else if (this->_energy_pts == 0)
    {
        std::cout << "ClapTrap: " << this->_name
            << " doesn't have enough energy points\n";
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    // if hit points >= amount, works as normal
    if (this->_hit_pts >= amount)
    {
        std::cout << "ClapTrap: " << this->_name
            << " gets damaged " << amount << " of hit points\n";
        this->_hit_pts -= amount;
    }
    // if hit points > 0 but < amount, decrease to 0
    else if (this->_hit_pts > 0)
    {
        std::cout << "ClapTrap: " << this->_name
            << " gets damaged " << _hit_pts << " of hit points\n";
        this->_hit_pts = 0;
    }
    // else hit points <= 0
    else
    {
        std::cout << "ClapTrap: " << this->_name
            << " can't take further damage cause it's out of hit points\n";
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    // check if has hit and energy points
    if (this->_hit_pts > 0 && this->_energy_pts > 0)
    {
        std::cout << "ClapTrap: " << this->_name
            << " repaired " << amount << " of hit points\n";
        this->_hit_pts += amount;
        this->_energy_pts--;
    }
    // if hit point = 0, print error msg
    else if (this->_hit_pts == 0)
    {
        std::cout << "ClapTrap: " << this->_name
            << " can't be repair cause it's out of hit points\n";
    }
    // if energy point = 0, print error msg
    else if (this->_energy_pts == 0)
    {
        std::cout << "ClapTrap: " << this->_name
            << " can't be repair cause it's out of energy points\n";
    }
}

/* [DEBUG function] */
void    ClapTrap::printStatus() const
{
    std::cout << "   [DEBUG]: "
        << "hit points: " << this->_hit_pts
        << "; energy points: " << this->_energy_pts
        << "; attack damage: " << this->_attack_dmg << std::endl;
}