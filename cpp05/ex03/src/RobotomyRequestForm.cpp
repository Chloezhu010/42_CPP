#include "../incl/RobotomyRequestForm.hpp"

/* default constructor */
RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

/* constructor */
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm: Constructor called" << std::endl;
}

/* copy constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
    if (this == &other) {
        return *this;
    }
    return *this;
}

/* destructor */
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

/* member functions */
void    RobotomyRequestForm::executeAction() const
{
    std::cout << "ZZZZZ Buzzzzzzzz drilling noise\n";
    
    // set a variable seed based on current time
    std::srand(time(0));
    if (std::rand() % 2 == 0)
    {
        std::cout << "🤖🤖 " << this->getName() << " has robotomized successfully\n";
    }
    else {
        std::cout << "❌❌ Robotomy failed on " << this->getName() << std::endl;
    }

}

/* getter */
std::string RobotomyRequestForm::getName() const
{
    return (this->_target);
}

/* setter */  

