/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:13 by chloe             #+#    #+#             */
/*   Updated: 2025/06/16 17:28:50 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

LiteralType detectType(const std::string& input)
{
    /* pseudo: nan, nanf, +-inff, +-inf */
    if (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
        return (TYPE_PSEUDO_F);
    if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf")
        return (TYPE_PSEUDO_D);
    /* single printable non-digit char */
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        return (TYPE_CHAR);
    /* int
        - if there is not '.' and not end with 'f', try convert to int
        - use the pos to avoid "123asdf"
    */
    if (input.find('.') == std::string::npos && input.back() != 'f')
    {
        try {
            std::size_t pos;
            std::stoi(input, &pos);
            if (pos == input.length())
                return (TYPE_INT);
        } catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    /* float
        - if endup with 'f', try convert to float
    */
    if (input.back() == 'f')
    {
        try {
            std::size_t pos;
            std::stof(input, &pos);
            if (pos == input.length())
                return (TYPE_FLOAT);
        } catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    /* double
        - if there is '.', try convert to double
    */
    if (input.find('.') != std::string::npos)
    {
        try {
            std::size_t pos;
            std::stod(input, &pos);
            if (pos == input.length())
                return (TYPE_DOUBLE);
        } catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    /* invalid */
    return (TYPE_INVALID);
}