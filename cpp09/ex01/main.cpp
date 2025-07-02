/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:50:50 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 22:10:47 by chloe            ###   ########.fr       */
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
    /* process input */
    RPN rpn;    
    try {
        int res = rpn.evaluate(av[1]);
        std::cout << res << "\n";
        // rpn.printStack();// debug
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
    return (0);
}