/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:40 by chloe             #+#    #+#             */
/*   Updated: 2025/06/16 21:19:36 by chloe            ###   ########.fr       */
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
void ScalarConverter::convert(std::string& input)
{
    int inputType = detectType(input);
    std::cout << "[DEBUG]: input type: " << inputType << std::endl; // debug
    
    /* switch between type */
    switch (inputType)
    {
        case TYPE_CHAR:
            convertFromChar(input);
            break ;
        case TYPE_INT:
            convertFromInt(input);
            break ;
        // case TYPE_FLOAT:
        //     convertFromFloat(input);
        //     break ;
        // case TYPE_DOUBLE:
        //     convertFromDouble(input);
        //     break ;
        case TYPE_PSEUDO_F:
            convertFromPseudoF();
            break ;
        case TYPE_PSEUDO_D:
            convertFromPseudoD();
            break ;
        default:
            std::cout << "Error: Impossible to print or input not convertable\n";
            break ;
    }
}
