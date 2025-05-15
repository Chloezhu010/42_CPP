/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:10:05 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 13:16:20 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int size = 10;
    Zombie *horde = zombieHorde(size, "hordeZombie");
    
    for (int i = 0; i < size; i++)
    {
        std::cout << "Index " << i << ": ";
        horde[i].announce();
    }
    
    delete[] horde;
    return (0);
}