/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:49 by chloe             #+#    #+#             */
/*   Updated: 2025/06/29 20:46:39 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> // for ifstream
#include <string> // for getline
#include <map> // for std::map
#include <cstdlib> // for atof
#include <sstream> // for stringstream
#include <limits>

int main(int ac, char **av)
{
    /* input count check */
    if (ac != 2)
    {
        std::cerr << "Error: Neet an input file\n";
        return (1);
    }
    /* input file check */
    std::ifstream file(av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: Failed to open the file\n";
        return (1);
    }
    // /* DEBUG printout the input file */
    // std::string line;
    // while (std::getline(file, line))
    //     std::cout << line << std::endl;
    
    /* parse input into map container */
    std::string line;
    std::map<std::string, double> btcMap;
    // skip the first line
    std::getline(file, line);
    // start parsing
    while (std::getline(file, line))
    {
        size_t delimiterPos = line.find(" | ");
        // extract the date, value in string
        if (delimiterPos != line.npos)
        {
            std::string date = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 3, line.npos);
            // convert the value from str to float, inset to the map container
            std::istringstream iss(valueStr);
            double value;
            if (iss >> value)
            {
                if (value < 0)
                    std::cout << "Error: not a positive number.\n";
                else if (value > 2147483647)
                    std::cout << "Error: too large a number.\n";
                else
                    btcMap.insert(std::make_pair(date, value)); 
            }
            else
                std::cerr << "Error: Invalid value\n";    
        }
        else
            std::cerr << "Error: Invalid line\n";
    }
    
    /* DEBUG printout the map key-value */
    std::map<std::string, double>::const_iterator it;
    for (it = btcMap.begin(); it != btcMap.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
    
    file.close();
    
    return (0);
}