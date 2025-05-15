/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:09:47 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 13:15:26 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* constructor
    - use initialization list rather than assignment, for better efficiency
*/
Zombie::Zombie(std::string name): _name(name)
{
    std::cout << "Zombie " << _name << " created" << std::endl;
}

/* destructor */
Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

/* announce function */
void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}