/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:43 by chloe             #+#    #+#             */
/*   Updated: 2025/06/16 23:07:53 by chloe            ###   ########.fr       */
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
        ScalarConverter::convert(input);

        // std::cout << "\nDEBUG\n";
        // float f = std::stof(input);
        // bool isWholeFloat = (f == static_cast<int>(f));
        // if (isWholeFloat)
        //     std::cout << f << std::endl;
        // else
        //     std::cout << "not\n";
    }
}