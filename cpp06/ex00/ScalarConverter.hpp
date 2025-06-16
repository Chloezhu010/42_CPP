/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:35 by chloe             #+#    #+#             */
/*   Updated: 2025/06/16 15:39:45 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

enum LiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO_F,
    TYPE_PSEUDO_D,
    TYPE_INVALID,
};

class ScalarConverter
{
    private:
        
    public:
        /* constructors */
        ScalarConverter();                         
        ScalarConverter(const ScalarConverter& other);
        
        /* operator overload */
        ScalarConverter& operator=(const ScalarConverter& other);
        
        /* destructor */
        virtual ~ScalarConverter() = 0; // pure virtual function

        /* member functions */
        static void convert(std::string input);

        /* getters */

};

LiteralType detectType(const std::string& input);

#endif
