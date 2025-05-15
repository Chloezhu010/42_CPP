/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:32:10 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 16:39:38 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

Weapon::Weapon(std::string type)
{
    setType(type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}

const std::string &Weapon::getType() const
{
    return (_type);
}
