/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:33:06 by chloe             #+#    #+#             */
/*   Updated: 2025/06/07 12:21:38 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/Bureaucrat.hpp"

/* default constructor */
Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}


/* constructor */
Bureaucrat::Bureaucrat(std::string name): _name(name)
{
    std::cout << "Bureaucrat: Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << "Bureaucrat: Constructor called" << std::endl;
    try
    {
        this->setGrade(grade);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what();
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what();
    }
}

/* copy constructor */
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_grade = other.getGrade();
    }
    return *this;
}

/* destructor */
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: Destructor called" << std::endl;
}

/* member functions */
void Bureaucrat::incrementGrade()
{
    // std::cout << "Bureaucrat: incrementGrade called" << std::endl;
    try
    {
        int grade = getGrade();
        this->setGrade(grade - 1);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what();
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what();
    }
} 

void Bureaucrat::decrementGrade()
{
    // std::cout << "Bureaucrat: decrementGrade called" << std::endl;
    try
    {
        int grade = getGrade();
        this->setGrade(grade + 1);
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what();
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what();
    }
}

void Bureaucrat::signForm(AForm& form)
{
    try {
        form.beSign(*this);
    }
    catch (std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                    << " because " << e.what();
        return ;
    }
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

/* 
    - check if form is signed
    - try to execute it
    - log success / failure
*/
void Bureaucrat::executeForm(AForm const& form)
{

}

/* getter */
std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int         Bureaucrat::getGrade() const
{
    return (this->_grade);
}

/* setter */
void        Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

/* overload operator */
std::ostream    &operator<<(std::ostream &out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade "
        << b.getGrade();
    return (out);
}

// /* debug */
// void    Bureaucrat::printInfo()
// {
//     std::cout << "Name: " << this->getName() 
//                 << "; Grade: " << this->getGrade()
//                 << std::endl;
// }