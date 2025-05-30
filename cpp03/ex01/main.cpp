/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:33 by czhu              #+#    #+#             */
/*   Updated: 2025/05/30 12:16:34 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Constructors ---\n";
    ClapTrap alice("Alice");
    ScavTrap bob("Bob");
    ScavTrap cathy;
    ScavTrap david = bob;

    // alice.printStatus();
    // bob.printStatus();
    // cathy.printStatus();
    // david.printStatus();
    
    std::cout << "\n--- Valid actions ---\n";
    alice.attack("Bob");
    // alice.printStatus();
    // bob.printStatus();
    
    bob.takeDamage(2);
    // bob.printStatus();
    
    bob.beRepaired(1);
    // bob.printStatus();

    bob.guardGate();
    // bob.printStatus();

    std::cout << "\n--- Invalid actions ---\n";
    bob.takeDamage(100);
    // bob.printStatus();
    bob.attack("Alice");
    // bob.beRepaired(2);
    bob.guardGate();
   
    for (int i = 0; i < 51; i++)
    {
        david.attack("Alice");
        // david.printStatus();
    }
    bob.beRepaired(3);
    bob.guardGate();

    std::cout << "\n--- Destructors ---\n";
    return (0);
}
