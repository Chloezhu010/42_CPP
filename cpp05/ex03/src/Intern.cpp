#include "../incl/Intern.hpp"

/* default constructor */
Intern::Intern()
{
    std::cout << "Intern: Default constructor called" << std::endl;
}

/* copy constructor */
Intern::Intern(const Intern& other)
{
    std::cout << "Intern: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Intern: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
Intern::~Intern()
{
    std::cout << "Intern: Destructor called" << std::endl;
}

/* member functions */
static AForm*    makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm*    makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm*    makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm*    Intern::makeForm(std::string formName, std::string target)
{
    // using array & func pointer
    const std::string name[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };
    
    AForm* (*creator[3])(std::string) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePresidential,
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == name[i])
        {
            std::cout << "Intern creates " << name[i] << std::endl;
            return (creator[i](target));
        }           
    }
    std::cout << "Fail to create form\n";
    return NULL;
}

/* getter */

/* setter */  

