/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:47:33 by chloe             #+#    #+#             */
/*   Updated: 2025/05/30 12:55:33 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->_hit_pts = FragTrap::_hit_pts;
    this->_energy_pts = ScavTrap::_energy_pts;
    this->_attack_dmg = FragTrap::_attack_dmg;   
    std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hit_pts = FragTrap::_hit_pts;
    this->_energy_pts = ScavTrap::_energy_pts;
    this->_attack_dmg = FragTrap::_attack_dmg;    
    std::cout << "DiamondTrap: Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other)
{
    std::cout << "DiamondTrap: Copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_hit_pts = other._hit_pts;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
        this->_name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I'm " << _name
            << ", and my ClapTrap name is "
            << ClapTrap::_name << std::endl;
}