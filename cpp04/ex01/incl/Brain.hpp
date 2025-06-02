#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        /* constructors */
        Brain();                              
        Brain(const Brain& other);    
        
        /* operator overload */
        Brain& operator=(const Brain& other); 
        
        /* destructor */
        ~Brain();

        /* member functions */

        /* getter */
        std::string getIdea(int index) const;

        /* setter */
        void    setIdea(int index, const std::string& idea);                
};

#endif
