/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:35 by chloe             #+#    #+#             */
/*   Updated: 2025/06/17 12:20:07 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#include <cfloat>
#include <climits>

enum LiteralType {
    TYPE_CHAR = 0,
    TYPE_INT = 1,
    TYPE_FLOAT = 2,
    TYPE_DOUBLE = 3,
    TYPE_PSEUDO_F = 4,
    TYPE_PSEUDO_D = 5,
    TYPE_INVALID = 6,
};

class ScalarConverter
{
    private:
        /* constructors */
        ScalarConverter();                         
        ScalarConverter(const ScalarConverter& other);
        
        /* operator overload */
        ScalarConverter& operator=(const ScalarConverter& other);
        
        /* destructor */
        virtual ~ScalarConverter() = 0; // pure virtual function
    public:
        static void convert(std::string& input);
};

LiteralType detectType(const std::string& input);
void        convertFromChar(std::string& input);
void        convertFromInt(std::string& input);
void        convertFromFloat(std::string& input);
void        convertFromDouble(std::string& input);
void        convertFromPseudoF(std::string& input);
void        convertFromPseudoD(std::string& input);

#endif
