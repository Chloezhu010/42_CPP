/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:33:00 by chloe             #+#    #+#             */
/*   Updated: 2025/06/07 11:45:07 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade; // range from 1 (highest) to 150 (lowest)
    public:
        /* constructors */
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, int grade);                          
        Bureaucrat(const Bureaucrat& other);    
        
        /* operator overload */
        Bureaucrat& operator=(const Bureaucrat& other); 
        
        /* destructor */
        ~Bureaucrat();

        /* member functions */
        void incrementGrade();
        void decrementGrade();

        /* getter */
        std::string getName() const;
        int         getGrade() const;

        /* setter */
        void        setGrade(int grade);

        /* exception */
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "Grade is too high\n";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "Grade is too low\n";
                }
        };
        // /* debug */
        // void    printInfo();
};

/* overload << operator */
std::ostream    &operator<<(std::ostream &out, const Bureaucrat& b);


#endif
