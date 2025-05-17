/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:59:14 by czhu              #+#    #+#             */
/*   Updated: 2025/05/17 13:39:49 by chloe            ###   ########.fr       */
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
    std::cout << "[DEBUG]: I love having extra bacon for my double cheese burger!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]: I think I deserve to have some etra bacon for free" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]: This is unacceptable!" << std::endl;
}

/* ptr to output functions based on the level */
void    Harl::complain(std::string level)
{
    // array of level names
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    // array of member function ptrs
    void    (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return ;
        }
    }
    // if no matching level found
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}