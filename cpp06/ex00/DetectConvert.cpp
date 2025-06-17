/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:13 by chloe             #+#    #+#             */
/*   Updated: 2025/06/17 14:07:53 by czhu             ###   ########.fr       */
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
        if (input[input.length() - 1] == 'f')
        {
            const char* str = input.c_str(); // convert const std::string to const char*
            char* endptr;
            strtof(str, &endptr);
            if (endptr == &str[strlen(str) - 1])
                return (TYPE_FLOAT);           
            return (TYPE_INVALID);
        }
        /* check for double, int */
        const char* str = input.c_str();
        char* endptr;
        double d = strtod(str, &endptr);
        if (endptr != &str[strlen(str)])
            std::cerr << "Error: Invalid\n";        
        /* check for int */
        if (input.find('.') == std::string::npos && input[input.length() - 1] != 'f')
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
    const char* str = input.c_str();
    int  i = strtol(str, NULL, 10);
    /* char output */
    if (i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(i);
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }    
    /* int output */
    std::cout << "int: " << static_cast<int>(i) << std::endl;
    /* float output */
    std::cout << "float: " << static_cast<float>(i)  << ".0f" << std::endl;
    /* double output */
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void        convertFromFloat(std::string& input)
{
    const char* str = input.c_str();
    float f = strtof(str, NULL);
    bool isWholeFloat = (f == std::floor(f));

    /* char output */
    if (f < 0 || f > 127)
        std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(f);
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }
        
    /* int output */
    if ((int)f >= INT_MIN && (int)f <= INT_MAX)
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
    const char* str = input.c_str();
    double d = strtod(str, NULL);
    bool isWholeDouble = (d == std::floor(d));

    /* char output */
    if (d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(d);
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }
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
    if (d > DBL_MAX || d < DBL_MIN)
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    else
    {
        if (isWholeDouble)
            std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(d) << std::endl;   
    }
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