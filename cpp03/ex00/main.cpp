/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:33 by czhu              #+#    #+#             */
/*   Updated: 2025/05/30 12:03:00 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "---Constructors---\n";
    ClapTrap alice("Alice");
    ClapTrap bob("Bob");
    ClapTrap cathy;
    
    // cathy.printStatus();
    cathy = bob;
    // cathy.printStatus();
    // alice.printStatus();
    // bob.printStatus();

    std::cout << "\n---Valid actions---\n";
    alice.attack("Dummy");
    // alice.printStatus();

    alice.takeDamage(9);
    // alice.printStatus();
    
    alice.beRepaired(5);
    // alice.printStatus();

    alice.takeDamage(9);
    // alice.printStatus();

    std::cout << "\n---Invalid actions---\n";
    for (int i = 0; i < 11; i++)
    {
        bob.attack("Robot");
        // bob.printStatus();    
    }
    bob.beRepaired(3);
    // bob.printStatus();
    
    std::cout << "\n---Destructors---\n";
    return (0);
}
