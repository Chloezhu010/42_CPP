/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:35:42 by chloe             #+#    #+#             */
/*   Updated: 2025/05/29 22:21:58 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    this->_hit_pts = 100;
    this->_energy_pts = 100;
    this->_attack_dmg = 30;
    std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_hit_pts = 100;
    this->_energy_pts = 100;
    this->_attack_dmg = 30;
    std::cout << "FragTrap: Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout << "FragTrap: Copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        // this->_name = other._name;
        // this->_hit_pts = other._hit_pts;
        // this->_energy_pts = other._energy_pts;
        // this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
     if (this->_energy_pts <= 0)
    {
        std::cout << "FragTrap: " << this->_name
            << " doesn't have enough energy points\n";
        return ;
    }
    if (this->_hit_pts <= 0)
    {
        std::cout << "FragTrap: " << this->_name
            << " doesn't have enough hit points\n";
        return ;
    }
    std::cout << "FragTrap: " << this->_name
            << " gives a high five ✋✋\n";
}
