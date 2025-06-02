#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMasteria.hpp"
#include <iostream>

class ICharacter
{
    private:
        // Add member variables here
    public:
        /* constructors */
        ICharacter();   
        ICharacter(const ICharacter& other);    
        
        /* operator overload */
        ICharacter& operator=(const ICharacter& other); 
        
        /* destructor */
        virtual ~ICharacter(){};

        /* member functions */
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria *m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;

        /* getter */

        /* setter */                        
};

#endif
