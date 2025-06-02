#include "AMateria.hpp"

/* default constructor */
AMateria::AMateria()
{
    std::cout << "AMateria: Default constructor called" << std::endl;
}

/* constructors */
AMateria::AMateria(std::string const & type): _type(type)
{
    std::cout << "AMaterial: Constructor called\n";
}

/* copy constructor */
AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

/* destructor */
AMateria::~AMateria()
{
    std::cout << "AMateria: Destructor called" << std::endl;
}

/* member functions */
void    AMateria::use(ICharacter& target)
{
    std::cout << "AMateria: used " << target.getName() << std::endl;
}

/* getter */
std::string const & AMateria::getType() const
{
    return (this->_type);
}

/* setter */  

