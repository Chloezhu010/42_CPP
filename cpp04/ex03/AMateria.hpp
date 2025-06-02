#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
    protected:
        std::string _type;
    public:
        /* constructors */
        AMateria();
        AMateria(std::string const & type);                              
        AMateria(const AMateria& other);    
        
        /* operator overload */
        AMateria& operator=(const AMateria& other); 
        
        /* destructor */
        virtual ~AMateria();

        /* member functions */
        virtual AMateria* clone() const = 0; // pure virtual, make this class abstract
        virtual void use(ICharacter& target); // display effects

        /* getter */
        std::string const & getType() const; // return the materia type

        /* setter */                        
};

#endif
