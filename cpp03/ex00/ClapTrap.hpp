#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
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
};

#endif
