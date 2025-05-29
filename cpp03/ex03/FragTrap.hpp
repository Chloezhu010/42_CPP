/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:35:46 by chloe             #+#    #+#             */
/*   Updated: 2025/05/29 22:07:26 by chloe            ###   ########.fr       */
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
