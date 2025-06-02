#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        /* constructors */
        Dog();
        Dog(const Dog& other);
        
        /* operator overload */
        Dog& operator=(const Dog& other);            
       
        /* destructor */
        ~Dog();    
        
        /* member functions */
        void    makeSound() const;

        /* getter */
        Brain*  getBrain() const;

        /* setter */
};

#endif
