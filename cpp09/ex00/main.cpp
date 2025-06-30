/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:49 by chloe             #+#    #+#             */
/*   Updated: 2025/06/30 22:09:06 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    /* input count check */
    if (ac != 2)
    {
        std::cerr << "Error: Neet an input file\n";
        return (1);
    }
    /* load data.csv */
    BitcoinExchange exchange;
    try {
        exchange.loadData("data.csv");
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // printMap(exchange.getMap()); // debug
    /* process input file */
    try {
        exchange.processInput(av[1]);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
   
    
    return (0);
}