/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:40 by chloe             #+#    #+#             */
/*   Updated: 2025/06/15 17:49:08 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* default constructor */
ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

/* copy constructor */
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    std::cout << "ScalarConverter: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    std::cout << "ScalarConverter: Copy assignment operator called" << std::endl;
    if (this == &other) {
        return *this;
    }
    return *this;
}

/* destructor */
ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter: Destructor called" << std::endl;
}

/* member functions */



