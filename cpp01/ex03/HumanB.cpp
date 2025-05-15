/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:04:37 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 17:43:25 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

void    HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}