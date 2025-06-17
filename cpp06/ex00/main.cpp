/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:43 by chloe             #+#    #+#             */
/*   Updated: 2025/06/17 13:26:44 by czhu             ###   ########.fr       */
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
    /* convert input */
    else
    {
        std::string input = av[1];
        ScalarConverter::convert(input);
    }
    return (0);
}