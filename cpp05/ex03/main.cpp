/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:26:28 by chloe             #+#    #+#             */
/*   Updated: 2025/06/09 14:06:36 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Bureaucrat.hpp"
#include "incl/Form.hpp"
#include "incl/ShrubberyCreationForm.hpp"
#include "incl/RobotomyRequestForm.hpp"
#include "incl/PresidentialPardonForm.hpp"
#include "incl/Intern.hpp"

int main()
{
    std::cout << "----Constructors----\n";
    Intern randomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* random;
    Bureaucrat A("Alice", 1);
    
    std::cout << "\n----Test rrf----\n";
    rrf = randomIntern.makeForm("robotomy request", "Bender");
    try {
        rrf->beSigned(A);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
    A.executeForm(*rrf);

    std::cout << "\n----Test scf----\n";
    scf = randomIntern.makeForm("shrubbery creation", "Tree");
    try {
        scf->beSigned(A);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
    A.executeForm(*scf);

    std::cout << "\n----Test ppf----\n";
    ppf = randomIntern.makeForm("presidential pardon", "Pardon");
    try {
        ppf->beSigned(A);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
    A.executeForm(*ppf);

    std::cout << "\n----Test random----\n";
    random = randomIntern.makeForm("random", "laskjdlfk");

    std::cout << "\n----Destructors----\n";
    delete rrf;
    delete random;
    delete scf;
    delete ppf;
    
    return (0);
}