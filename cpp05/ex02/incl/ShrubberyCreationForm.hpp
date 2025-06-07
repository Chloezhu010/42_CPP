#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "./Form.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        // Add member variables here
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

        /* getter */

        /* setter */
};

#endif
