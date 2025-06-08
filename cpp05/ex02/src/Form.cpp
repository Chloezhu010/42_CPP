#include "../incl/Form.hpp"
#include "../incl/Bureaucrat.hpp"

/* default constructor */
AForm::AForm(): _name("default"), _sign(false), _gradeToSign(150), _gradeToExec(150)
{
    std::cout << "Form: Default constructor called" << std::endl;
}

/* constructor */
AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "Form: Constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

/* copy constructor */
AForm::AForm(const AForm& other): _name(other._name), _sign(other._sign), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "Form: Copy constructor called" << std::endl;
}

/* copy assignment operator */
AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Form: Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

/* destructor */
AForm::~AForm()
{
    std::cout << "Form: Destructor called" << std::endl;
}

/* member functions */
void    AForm::beSign(Bureaucrat& signer)
{
    if (signer.getGrade() <= this->getGradeToSign())
        this->_sign = true;
    else
        throw GradeTooLowException();
}

/* execute the form in the concrete classes
    - check the form is signed
    - grade of the bureaucrat is high enough to execute the form
    - otherwise through an exception
*/
void    AForm::execute(Bureaucrat const& executor) const
{
    if (this->getSign() == false)
        throw NoSignException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    executeAction();
}

/* getter */
std::string AForm::getName() const
{
    return (this->_name);
}

bool        AForm::getSign() const
{
    return (this->_sign);
}

int         AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int         AForm::getGradeToExec() const
{
    return (this->_gradeToExec);
}

/* setter */  

/* operator << overload */
std::ostream    &operator<<(std::ostream &out, const AForm& form)
{
    out << "Form: " << form.getName()
        << "\n\tSign status: " << form.getSign()
        << "\n\tGrade to sign: " << form.getGradeToSign()
        << "\n\tGrade to execute: " << form.getGradeToExec();
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