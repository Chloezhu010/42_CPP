/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:26:28 by chloe             #+#    #+#             */
/*   Updated: 2025/06/08 23:11:24 by chloe            ###   ########.fr       */
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
    AForm* random;
    
    std::cout << "\n----Test rrf----\n";
    rrf = randomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
        std::cout << "Created form: " << rrf->getName() << std::endl;

    std::cout << "\n----Test random----\n";
    random = randomIntern.makeForm("random", "laskjdlfk");
    if (random)
        std::cout << "Created form: " << random->getName() << std::endl;

    std::cout << "\n----Destructors----\n";
    delete rrf;
    delete random;
    
    return (0);
}