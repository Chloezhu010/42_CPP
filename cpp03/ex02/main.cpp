/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:33 by czhu              #+#    #+#             */
/*   Updated: 2025/05/30 12:48:03 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- Constructors ---\n";
    ClapTrap alice("Alice");
    // ClapTrap *ptr = new ScavTrap();
    FragTrap bob("Bob");
    FragTrap cathy;
    FragTrap david = bob;
    
    std::cout << "\n--- Valid actions ---\n";
    // ptr->attack("enemgy");
    // ptr->printStatus();

    alice.attack("Bob");
    // alice.printStatus();
    // // bob.printStatus();
    
    bob.takeDamage(2);
    // bob.printStatus();
    
    bob.beRepaired(1);
    // bob.printStatus();

    bob.highFivesGuys();
    // bob.printStatus();

    std::cout << "\n--- Invalid actions ---\n";
    bob.takeDamage(100);
    // bob.printStatus();
    bob.attack("Alice");
    bob.beRepaired(2);
    bob.highFivesGuys();
   
    for (int i = 0; i < 101; i++)
    {
        david.attack("Alice");
        // david.printStatus();
    }

    std::cout << "\n--- Destructors ---\n";
    return (0);
}
