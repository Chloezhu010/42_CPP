#include "Form.hpp"
#include "Bureaucrat.hpp"

/* default constructor */
Form::Form(): _name("default"), _sign(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "Form: Default constructor called" << std::endl;
}

/* constructor */
Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "Form: Constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

/* copy constructor */
Form::Form(const Form& other): _name(other._name), _sign(other._sign), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "Form: Copy constructor called" << std::endl;
}

/* copy assignment operator */
Form& Form::operator=(const Form& other)
{
    std::cout << "Form: Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

/* destructor */
Form::~Form()
{
    std::cout << "Form: Destructor called" << std::endl;
}

/* member functions */
void    Form::beSigned(Bureaucrat& signer)
{
    if (signer.getGrade() <= this->getGradeToSign())
        this->_sign = true;
    else
        throw GradeTooLowException();
}

/* getter */
std::string Form::getName() const
{
    return (this->_name);
}

bool        Form::getSign() const
{
    return (this->_sign);
}

int         Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int         Form::getGradeToExec() const
{
    return (this->_gradeToExec);
}

/* setter */  

/* operator << overload */
std::ostream    &operator<<(std::ostream &out, const Form& form)
{
    out << "Form name: " << form.getName()
        << "; Sign status: " << form.getSign()
        << "; Grade to sign: " << form.getGradeToSign()
        << "; Grade to execute: " << form.getGradeToExec();
    return (out);
}

/* debug */
// void    Form::printInfo()
// {
//     std::cout << "   [DEBUG] Form name: " << this->getName() 
//                 << "; Sign status: " << this->getSign()
//                 << "; Sign grade: " << this->getGradeToSign()
//                 << "; Exec grade: " << this->getGradeToExec()
//                 << std::endl;
// }