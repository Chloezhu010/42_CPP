/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:22:19 by chloe             #+#    #+#             */
/*   Updated: 2025/05/20 17:20:29 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* constructor & destructor */
Harl::Harl()
{}

Harl::~Harl()
{}

/* simple output functions */
void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my double cheese burger!" << std::endl;
    std::cout << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money" << std::endl;
    std::cout << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some etra bacon for free" << std::endl;
    std::cout << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << std::endl;
}

/* output functions based on the level */
void    Harl::complain(std::string level)
{
    int i = 0;

    // array of levels
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    // match the input with the levels array
    while (i < 4)
    {
        if (level == levels[i])
            break ;
        i++;
    }
    // switch the output based on the level i
    switch(i)
    {
        case 0:
                std::cout << "[ DEBUG ]\n";
                Harl::debug();
                // std::cout << "[ INFO ]" << std::endl;
                // Harl::info();
                // std::cout << "[ WARNING ]" << std::endl;
                // Harl::warning();
                // std::cout << "[ ERROR ]" << std::endl;
                // Harl::error();
                // break ;
        case 1:
                std::cout << "[ INFO ]\n";
                Harl::info();
                // std::cout << "[ WARNING ]" << std::endl;
                // Harl::warning();
                // std::cout << "[ ERROR ]" << std::endl;
                // Harl::error();
                // break ;
        case 2:
                std::cout << "[ WARNING ]\n";
                Harl::warning();
                // std::cout << "[ ERROR ]" << std::endl;
                // Harl::error();
                // break ;
        case 3:
                std::cout << "[ ERROR ]\n";
                Harl::error();
                break ;
        default:
                std::cout << "[ Probably complaining about insignificant problems ]\n";
                break ;
    }
}