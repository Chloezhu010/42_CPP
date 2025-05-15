/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:09:43 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 15:38:24 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* create a new zombie on the stack and announce itself */
void    randomChump(std::string name)
{
    Zombie  randomChump(name);
    randomChump.announce();
}