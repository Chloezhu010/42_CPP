/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:07 by chloe             #+#    #+#             */
/*   Updated: 2025/07/01 20:51:08 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* default constructor */
RPN::RPN()
{
    std::cout << "RPN: Default constructor called" << std::endl;
}

/* copy constructor */
RPN::RPN(const RPN& other)
{
    std::cout << "RPN: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
RPN& RPN::operator=(const RPN& other)
{
    std::cout << "RPN: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
RPN::~RPN()
{
    std::cout << "RPN: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

