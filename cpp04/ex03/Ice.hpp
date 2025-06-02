#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    private:
        std::string _type;
    public:
        /* constructors */
        Ice();                              
        Ice(const Ice& other);    
        
        /* operator overload */
        Ice& operator=(const Ice& other); 
        
        /* destructor */
        ~Ice();

        /* member functions */
        Ice* clone() const;
        void use(ICharacter& target);

        /* getter */

        /* setter */                        
};

#endif
