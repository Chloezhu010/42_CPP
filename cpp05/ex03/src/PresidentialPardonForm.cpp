#include "../incl/PresidentialPardonForm.hpp"

/* default constructor */
PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

/* constructor */
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm: Constructor called" << std::endl;
}

/* copy constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
    if (this == &other) {
        return *this;
    }
    return *this;
}

/* destructor */
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

/* member functions */
void    PresidentialPardonForm::executeAction() const
{
    std::cout << "✅✅ " << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

/* getter */
std::string PresidentialPardonForm::getName() const
{
    return (this->_target);
}

/* setter */  

