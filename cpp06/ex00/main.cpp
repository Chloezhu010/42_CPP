/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:43 by chloe             #+#    #+#             */
/*   Updated: 2025/06/16 21:15:39 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{  
    /* check input */
    if (ac != 2 || std::string(av[1]).empty())
    {
        std::cout << "Error: Need one input\n";
        return (1);
    }
    else
    {
        std::string input = av[1];
        // std::cout << detectType(av[1]) << std::endl; // debug

        ScalarConverter::convert(input);

        // float   f = static_cast<float>(42.0f);
        // double  d = static_cast<double>(42.0f);
        // char    c = static_cast<char>(0);

        // std::cout << std::showpoint << f << std::endl;
        // std::cout << d << std::endl;

        // if (std::isprint(c))
        //     std::cout << c << std::endl;
        // else
        //     std::cout << "char: Non displayable\n";

        // std::cout << "\nDEBUG\n";
        // std::size_t pos;
        // stof(input, &pos);
        // std::cout << pos << std::endl;
        // std::cout << input.length() << std::endl;
    }
}