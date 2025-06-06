#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _sign;
        const int           _gradeToSign;
        const int           _gradeToExec;
    public:
        /* constructors */
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);                
        Form(const Form& other);
        
        /* operator overload */
        Form& operator=(const Form& other);
        
        /* destructor */
        ~Form();

        /* member functions */
        void    beSign(Bureaucrat& signer);

        /* getter */
        std::string getName() const;
        bool        getSign() const;
        int         getGradeToSign() const;
        int         getGradeToExec() const;

        /* setter */

        /* exception */
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const _NOEXCEPT {
                    return "Form: Grade is too high\n";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const _NOEXCEPT {
                    return "Form: Grade is too low\n";
                }
        };

        /* debug */
        void    printInfo();
};

/* overload << operator */
std::ostream    &operator<<(std::ostream &out, const Form& form);

#endif
