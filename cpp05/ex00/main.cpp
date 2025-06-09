/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:26:28 by chloe             #+#    #+#             */
/*   Updated: 2025/06/09 12:35:15 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----Constructors----\n";
    int grade_high = 150;
    int grade_low = 1;
    
    Bureaucrat A("Alice", grade_high);
    Bureaucrat B("Bob", grade_low);
    std::cout << A << std::endl;
    std::cout << B << std::endl;

    std::cout << "\n----Increment grade----\n";
    A.incrementGrade();
    std::cout << A << std::endl;
    // for (int i = grade_high; i > 0; i--)
    //     A.incrementGrade();
    // std::cout << A << std::endl;

    std::cout << "\n----Decrement grade----\n";
    B.decrementGrade();
    std::cout << B << std::endl;
    // for (int i = grade_low; i < 151; i++)
    //     B.decrementGrade();
    // std::cout << B << std::endl;

    std::cout << "\n----Set random grade----\n";
    // /* Case 1: not using try/catch */
    // A.setGrade(0);
    // std::cout << A << std::endl;

    /* Case 2: use try/catch */
    try{
        A.setGrade(151);
    } 
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what();
    }
    std::cout << A << std::endl;

    try{
        B.setGrade(-1);
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what();
    }
    std::cout << B << std::endl;

    std::cout << "\n----Destructors----\n";
    return (0);
}