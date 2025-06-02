#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        /* constructors */
        Cat();
        Cat(const Cat& other);
        
        /* operator overload */
        Cat& operator=(const Cat& other);
        
        /* destructor */
        ~Cat();

        /* member functions */
        void    makeSound() const;

        /* getter */
        Brain*  getBrain() const;

        /* setter */                        
};

#endif
