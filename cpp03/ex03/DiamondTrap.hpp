/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:47:29 by chloe             #+#    #+#             */
/*   Updated: 2025/05/29 21:25:57 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        /* constructors */
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);    
        
        /* operator overload */
        DiamondTrap& operator=(const DiamondTrap& other); 
        
        /* destructor */
        ~DiamondTrap();    
        
        /* member functions */
        void    attack(const std::string& target);
        void    whoAmI();
};

#endif
