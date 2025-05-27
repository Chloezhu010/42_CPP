#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
    private:
        // Add member variables here
    public:
        /* constructors */
        ScavTrap();                              
        ScavTrap(const ScavTrap& other);    
        
        /* operator overload */
        ScavTrap& operator=(const ScavTrap& other); 
        
        /* destructor */
        ~ScavTrap();                            
};

#endif
