/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:33 by czhu              #+#    #+#             */
/*   Updated: 2025/05/30 14:29:07 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "--- Constructors ---\n";
    ClapTrap alice("Alice");
    DiamondTrap bob("Bob");
    DiamondTrap cathy;
    DiamondTrap david = bob;
    
    std::cout << "\n--- Valid actions ---\n";
    bob.whoAmI();
    bob.attack("Alice");
    // bob.printStatus();
    
    bob.takeDamage(2);
    // bob.printStatus();
    
    bob.beRepaired(1);
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
