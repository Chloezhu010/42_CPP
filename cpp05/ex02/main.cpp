/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:26:28 by chloe             #+#    #+#             */
/*   Updated: 2025/06/09 12:41:53 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Bureaucrat.hpp"
#include "incl/Form.hpp"
#include "incl/ShrubberyCreationForm.hpp"
#include "incl/RobotomyRequestForm.hpp"
#include "incl/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "----Constructors----\n";
    Bureaucrat A("Alice", 1);
    ShrubberyCreationForm shrubbery("shrub");
    RobotomyRequestForm   robot("robo");
    PresidentialPardonForm pardon("pardo");    

    std::cout << "\n----Test ShrubberyCreationForm----\n";
    std::cout << "----Basic info----\n";
    std::cout << shrubbery << std::endl;
    std::cout << A << std::endl;
    std::cout << "----Test execute()----\n";
    /* attempt to sign the form */
    try{
        shrubbery.beSigned(A);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    /* attempt to execute the form */
    try{
        shrubbery.execute(A);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << "----Test executeForm()----\n";
    A.executeForm(shrubbery);

    std::cout << "\n----Test RobotomyRequestForm----\n";
    std::cout << "----Basic info----\n";
    std::cout << robot << std::endl;
    std::cout << A << std::endl;
    std::cout << "----Test execute()----\n";
    /* attempt to sign the form */
    try{
        robot.beSigned(A);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    /* attempt to execute the form */
    try{
        robot.execute(A);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << "----Test executeForm()----\n";
    A.executeForm(robot);

    std::cout << "\n----Test PresidentialPardonForm----\n";
    std::cout << "----Basic info----\n";
    std::cout << pardon << std::endl;
    std::cout << A << std::endl;
    std::cout << "----Test execute()----\n";
    /* attempt to sign the form */
    try{
        pardon.beSigned(A);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    /* attempt to execute the form */
    try{
        pardon.execute(A);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << "----Test executeForm()----\n";
    A.executeForm(pardon);

    std::cout << "\n----Destructors----\n";
    
    return (0);
}