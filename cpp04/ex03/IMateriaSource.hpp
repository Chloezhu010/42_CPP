#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMasteria.hpp"
#include <iostream>

class IMateriaSource
{
    private:
        // Add member variables here
    public:
        /* constructors */
        IMateriaSource();                              
        IMateriaSource(const IMateriaSource& other);    
        
        /* operator overload */
        IMateriaSource& operator=(const IMateriaSource& other); 
        
        /* destructor */
        virtual ~IMateriaSource(){};

        /* member functions */
        virtual void    learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;

        /* getter */

        /* setter */                        
};

#endif
