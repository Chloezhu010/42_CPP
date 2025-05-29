/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:33 by czhu              #+#    #+#             */
/*   Updated: 2025/05/29 20:26:11 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- Constructors ---\n";
    ClapTrap alice("Alice");
    FragTrap bob("Bob");
    FragTrap cathy;
    FragTrap david = bob;
    
    std::cout << "\n--- Valid actions ---\n";
    alice.attack("Bob");
    alice.printStatus();
    bob.printStatus();
    
    bob.takeDamage(2);
    bob.printStatus();
    
    bob.beRepaired(1);
    bob.printStatus();

    bob.highFivesGuys();
    bob.printStatus();

    std::cout << "\n--- Invalid actions ---\n";
    bob.takeDamage(100);
    bob.printStatus();
    bob.attack("Alice");
    bob.beRepaired(2);
    bob.highFivesGuys();
   
    for (int i = 0; i < 101; i++)
    {
        david.attack("Alice");
        david.printStatus();
    }

    std::cout << "\n--- Destructors ---\n";
    return (0);
}
