#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
    private:
        // Add member variables here
    public:
        /* constructors */
        AMateria(std::string const & type);                              
        AMateria(const AMateria& other);    
        
        /* operator overload */
        AMateria& operator=(const AMateria& other); 
        
        /* destructor */
        ~AMateria();

        /* member functions */
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        /* getter */
        std::string const & getType() const; // return the materia type

        /* setter */                        
};

#endif
