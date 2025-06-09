#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <fstream> // for std::ofsttream
#include <cstdlib> // for rand(), srand()
#include <ctime> // for time()

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _sign;
        const int           _gradeToSign;
        const int           _gradeToExec;
    public:
        /* constructors */
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExec);                
        AForm(const AForm& other);
        
        /* operator overload */
        AForm& operator=(const AForm& other);
        
        /* destructor */
        ~AForm();

        /* member functions */
        void    beSigned(Bureaucrat& signer);
        virtual void    execute(Bureaucrat const& executor) const;
        virtual void    executeAction() const = 0; // will be overrided by concrete classes

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
                const char* what() const throw() {
                    return "AForm: Grade is too high\n";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "AForm: Grade is too low\n";
                }
        };
        class NoSignException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "AForm: Form not signed\n";
                }
        };

        // /* debug */
        // void    printInfo();
};

/* overload << operator */
std::ostream    &operator<<(std::ostream &out, const AForm& form);

#endif
