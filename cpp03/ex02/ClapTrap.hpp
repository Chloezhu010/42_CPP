/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:50:30 by czhu              #+#    #+#             */
/*   Updated: 2025/05/30 12:35:37 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string         _name;
        unsigned int        _hit_pts;
        unsigned int        _energy_pts;
        unsigned int        _attack_dmg;
    public:
        /* constructor */
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);

        /* operator overload */
        ClapTrap& operator=(const ClapTrap& other);

        /* destructor */
        ~ClapTrap();

        /* member functions */
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        /* debug */
        void    printStatus() const;
};

#endif
