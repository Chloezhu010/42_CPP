/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:12:48 by chloe             #+#    #+#             */
/*   Updated: 2025/05/29 17:16:02 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    this->_hit_pts = 100;
    this->_energy_pts = 50;
    this->_attack_dmg = 20;
    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_hit_pts = 100;
    this->_energy_pts = 50;
    this->_attack_dmg = 20;
    std::cout << "ScavTrap: Constructor called" << std::endl;
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
        this->_name = other._name;
        this->_hit_pts = other._hit_pts;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
     // check if has hit and energy points
    if (this->_hit_pts > 0 && this->_energy_pts > 0)
    {
        std::cout << "ScavTrap: " << this->_name << " attacks "
            << target << ", causing " << this->_attack_dmg
            << " points of damage!\n";
        this->_energy_pts--;
    }
    // if hit point = 0, print error msg
    else if (this->_hit_pts == 0 && this->_energy_pts > 0)
    {
        std::cout << "ScavTrap: " << this->_name
            << " doesn't have enough hit points\n";
        this->_energy_pts--;
    }
    // if energy point = 0, print error msg
    else if (this->_energy_pts == 0)
    {
        std::cout << "ScavTrap: " << this->_name
            << " doesn't have enough energy points\n";
    }
}

void    ScavTrap::guardGate()
{
    if (this->_energy_pts <= 0)
    {
        std::cout << "ScavTrap: " << this->_name
            << " doesn't have enough energy points\n";
        return ;
    }
    if (this->_hit_pts <= 0)
    {
        std::cout << "ScavTrap: " << this->_name
            << " doesn't have enough hit points\n";
        return ;
    }
    std::cout << "ScavTrap: " << this->_name
            << " is now in Gate keeper mode\n";
}