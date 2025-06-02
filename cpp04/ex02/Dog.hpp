#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        /* constructors */
        Dog();                              
       
        /* destructor */
        ~Dog();    
        
        /* member functions */
        void    makeSound() const;
};

#endif
