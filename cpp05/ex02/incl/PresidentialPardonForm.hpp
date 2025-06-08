#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "./Form.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        /* constructors */
        PresidentialPardonForm(); 
        PresidentialPardonForm(std::string target);                           
        PresidentialPardonForm(const PresidentialPardonForm& other);
        
        /* operator overload */
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        
        /* destructor */
        ~PresidentialPardonForm();

        /* member functions */
        void    executeAction() const;

        /* getter */
        std::string getName() const;

        /* setter */
};

#endif
