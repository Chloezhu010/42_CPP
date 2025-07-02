/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:50:50 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 14:33:16 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    /* input check */
    if (ac != 2)
    {
        std::cerr << "Error: Need one input, eg. \"3 4 +\"\n";
        return (1);
    }
    
    RPN test;    
    test.processToken(av[1]);
    test.printStack();    
    
    return (0);
}