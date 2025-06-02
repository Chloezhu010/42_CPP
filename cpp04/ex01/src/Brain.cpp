#include "../incl/Brain.hpp"

/* default constructor */
Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[i]="";
    std::cout << "Brain: Default constructor called" << std::endl;
}

/* copy constructor */
Brain::Brain(const Brain& other)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

/* copy assignment operator */
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

/* destructor */
Brain::~Brain()
{
    std::cout << "Brain: Destructor called" << std::endl;
}

/* member functions */

/* getter */
std::string Brain::getIdea(int index) const
{
    if (index>=0 && index < 100)
        return (ideas[index]);
    else
        return ("");
}

/* setter */  
void    Brain::setIdea(int index, const std::string& idea)
{
    if (index>=0 && index < 100)
        ideas[index] = idea;
    else
        std::cerr << "Brain: setIdea: invalid index\n";
}
