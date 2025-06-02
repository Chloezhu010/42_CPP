#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        /* constructors */
        WrongAnimal();                              
        WrongAnimal(const WrongAnimal& other);    
        
        /* operator overload */
        WrongAnimal& operator=(const WrongAnimal& other); 
        
        /* destructor */
        ~WrongAnimal();

        /* member functions */
        void    makeSound() const;

        /* getter */
        std::string    getType() const;                       
};

#endif
