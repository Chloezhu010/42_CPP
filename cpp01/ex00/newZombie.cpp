/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:09:38 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 15:38:26 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* create a new zombie on the heap with new */
Zombie  *newZombie(std::string name)
{
    Zombie  *newZombie;

    newZombie = new Zombie(name);
    return (newZombie);
}