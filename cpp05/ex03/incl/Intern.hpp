#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class Intern
{
    private:
        
    public:
        /* constructors */
        Intern();                         
        Intern(const Intern& other);
        
        /* operator overload */
        Intern& operator=(const Intern& other);
        
        /* destructor */
        ~Intern();

        /* member functions */
        AForm*    makeForm(std::string formName, std::string target);

        /* getter */

        /* setter */
};

#endif
