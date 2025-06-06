/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:26:28 by chloe             #+#    #+#             */
/*   Updated: 2025/06/06 22:04:45 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "----Constructors----\n";
    Bureaucrat A("Alice", 5);
    Form* form = NULL;
    
    /* check Form initialization */
    try {
        form = new Form("Form_404", 10, 50);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }
    if (form)
    {
        std::cout << "✅✅ check info ✅✅\n";
        std::cout << *form << std::endl;
    }
    else
        std::cout << "Form creation failed. Pointer is NULL.\n";
    
    std::cout << "\n----Check sign status----\n";
    try {
        form->beSign(A);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }
    A.signForm(*form);
    std::cout << "✅✅ check info ✅✅\n";
    std::cout << A << std::endl;
    std::cout << *form << std::endl;

    std::cout << "\n----Destructors----\n";
    delete form;
    
    return (0);
}