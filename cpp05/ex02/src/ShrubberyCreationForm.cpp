#include "ShrubberyCreationForm.hpp"

/* default constructor */
ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

/* constructor */
ShrubberyCreationForm::ShrubberyCreationForm(): 
{
    std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

/* copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

