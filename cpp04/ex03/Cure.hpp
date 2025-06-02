#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure
{
    private:
        // Add member variables here
    public:
        /* constructors */
        Cure();                              
        Cure(const Cure& other);    
        
        /* operator overload */
        Cure& operator=(const Cure& other); 
        
        /* destructor */
        ~Cure();

        /* member functions */

        /* getter */

        /* setter */                        
};

#endif
