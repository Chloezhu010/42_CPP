/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:12:54 by chloe             #+#    #+#             */
/*   Updated: 2025/05/30 14:28:39 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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
