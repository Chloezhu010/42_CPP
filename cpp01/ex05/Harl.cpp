/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:59:14 by czhu              #+#    #+#             */
/*   Updated: 2025/05/16 16:19:15 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
    
}