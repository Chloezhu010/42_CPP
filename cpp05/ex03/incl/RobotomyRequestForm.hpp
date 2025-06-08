#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "./Form.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
    public:
        /* constructors */
        RobotomyRequestForm();  
        RobotomyRequestForm(std::string target);                           
        RobotomyRequestForm(const RobotomyRequestForm& other);
        
        /* operator overload */
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        
        /* destructor */
        ~RobotomyRequestForm();

        /* member functions */
        void    executeAction() const;

        /* getter */
        std::string getName() const;

        /* setter */
};

#endif
