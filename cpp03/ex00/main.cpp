/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:33 by czhu              #+#    #+#             */
/*   Updated: 2025/05/27 15:56:11 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap alice("Alice");
    ClapTrap bob("Bob");
    
    alice.attack("Dummy");
    alice.printStatus();

    alice.takeDamage(9);
    alice.printStatus();
    
    alice.beRepaired(5);
    alice.printStatus();

    alice.takeDamage(9);
    alice.printStatus();

    for (int i = 0; i < 10; i++)
    {
        bob.attack("Robot");
        bob.printStatus();    
    }
    bob.beRepaired(3);
    bob.printStatus();

    return (0);
}
