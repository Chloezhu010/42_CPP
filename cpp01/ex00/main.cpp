/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:09:31 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 15:38:27 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    // stack allocation
    Zombie stackZombie("stackZombie");
    stackZombie.announce();

    // heap allocation
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;

    // random chump
    randomChump("randomChump");
    return (0);
}