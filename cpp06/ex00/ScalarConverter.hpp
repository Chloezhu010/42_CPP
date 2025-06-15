/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:35 by chloe             #+#    #+#             */
/*   Updated: 2025/06/15 23:14:37 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

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

#endif
