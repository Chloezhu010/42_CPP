/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:12:54 by chloe             #+#    #+#             */
/*   Updated: 2025/05/29 16:37:24 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        /* constructors */
        ScavTrap();
        ScavTrap(std::string name);                           
        ScavTrap(const ScavTrap& other);    
        
        /* operator overload */
        ScavTrap& operator=(const ScavTrap& other); 
        
        /* destructor */
        ~ScavTrap();

        /* member function */
        void    attack(const std::string& target);
        void    guardGate();
};

#endif
