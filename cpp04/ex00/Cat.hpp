#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        // Add member variables here
    public:
        /* constructors */
        Cat();                              
        
        /* destructor */
        ~Cat();

        /* member functions */
        void    makeSound() const;

        /* getter */

        /* setter */                        
};

#endif
