/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:35:46 by chloe             #+#    #+#             */
/*   Updated: 2025/05/30 12:56:25 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
    private:
        // Add member variables here
    public:
        /* constructors */
        FragTrap();
        FragTrap(std::string name);                          
        FragTrap(const FragTrap& other);    
        
        /* operator overload */
        FragTrap& operator=(const FragTrap& other); 
        
        /* destructor */
        ~FragTrap();
        
        /* member functions */
        void    highFivesGuys(void);
};

#endif
