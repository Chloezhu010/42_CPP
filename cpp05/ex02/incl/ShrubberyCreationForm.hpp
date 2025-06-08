#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "./Form.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
    public:
        /* constructors */
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        
        /* operator overload */
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        
        /* destructor */
        ~ShrubberyCreationForm();

        /* member functions */
        void    executeAction() const;

        /* getter */
        std::string    getName() const;

        /* setter */
};

#endif
