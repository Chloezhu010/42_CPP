#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        /* constructors */
        WrongCat();                              
        
        /* destructor */
        ~WrongCat();

        /* member functions */
        void    makeSound() const;              
};

#endif
