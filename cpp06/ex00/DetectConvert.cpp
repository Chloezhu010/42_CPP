/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:13 by chloe             #+#    #+#             */
/*   Updated: 2025/06/16 23:23:54 by chloe            ###   ########.fr       */
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
    /* float, double, int */
    try {
        /* check for float */
        if (input.back() == 'f')
        {
            std::size_t pos;
            std::stof(input, &pos);
            if (pos == input.length() - 1)
                return (TYPE_FLOAT);
            return (TYPE_INVALID);
        }
        /* check for double, int */
        std::size_t pos;
        double      d = std::stod(input, &pos);
        if (pos != input.length())
            throw (std::invalid_argument("Invalid"));
        /* check for int */
        if (input.find('.') == std::string::npos && input.back() != 'f')
        {
            /* check int range */
            if (d >= INT_MIN && d <= INT_MAX)
                return (TYPE_INT);
        }
        
        return (TYPE_DOUBLE);
    } catch (std::exception& e)
    {
        return (TYPE_INVALID);
    }
}

void        convertFromChar(std::string& input)
{    
    std::cout << "char: " << "'" << input << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) 
                            << static_cast<float>(input[0])  << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}

void        convertFromInt(std::string& input)
{
    int i = std::stoi(input);
    char c = static_cast<char>(i);

    /* char output */
    if (c >= 0 && c <= 127)
    {
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    /* int output */
    std::cout << "int: " << static_cast<int>(i) << std::endl;
    /* float output */
    std::cout << "float: " << static_cast<float>(i)  << ".0f" << std::endl;
    /* double output */
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void        convertFromFloat(std::string& input)
{
    float f = std::stof(input);
    bool isWholeFloat = (f == std::floor(f));
    char c = static_cast<char>(f);

    /* char output */
    if (c >= 0 && c <= 127)
    {
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    /* int output */
    if (f >= INT_MIN && f <= INT_MAX)
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible\n";
    /* float output */
    if (isWholeFloat)
        std::cout << "float: " << static_cast<float>(f)  << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(f)  << "f" << std::endl;
    /* double output */
    if (isWholeFloat)
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void        convertFromDouble(std::string& input)
{
    double d = std::stod(input);
    bool isWholeDouble = (d == std::floor(d));
    char c = static_cast<char>(d);

    /* char output */
    if (c >= 0 && c <= 127)
    {
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    /* int output */
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible\n";
    /* float output */
    if (d >= -FLT_MAX && d <= FLT_MAX)
    {
        if (isWholeDouble)
            std::cout << "float: " << static_cast<float>(d)  << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(d)  << "f" << std::endl;
    }
    else
        std::cout << "float: impossible\n";
    /* double output */
    if (isWholeDouble)
        std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void        convertFromPseudoF(std::string& input)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << input << std::endl;
    std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
}

void        convertFromPseudoD(std::string& input)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << input << "f" << std::endl;
    std::cout << "double: " << input << std::endl;
}