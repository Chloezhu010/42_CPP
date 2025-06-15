/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:29:43 by chloe             #+#    #+#             */
/*   Updated: 2025/06/15 17:50:10 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{  
    (void)av;
    /* check input */
    if (ac != 2)
    {
        std::cout << "Error: Usage <input>\n";
    }
    else
    {
        float   f = static_cast<float>(42.0f);
        double  d = static_cast<double>(42.0f);
        char    c = static_cast<char>(0);

        std::cout << std::showpoint << f << std::endl;
        std::cout << d << std::endl;

        if (std::isprint(c))
            std::cout << c << std::endl;
        else
            std::cout << "char: Non displayable\n";
    }
}