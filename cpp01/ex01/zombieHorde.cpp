/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:10:18 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 13:10:19 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *zombieHorde;

    zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombieHorde[i] = Zombie(name);
    return (zombieHorde);
}