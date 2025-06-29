/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:41 by chloe             #+#    #+#             */
/*   Updated: 2025/06/29 22:50:24 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* default constructor */
BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

/* copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    std::cout << "BitcoinExchange: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->btcRate = other.btcRate;
    }
    return *this;
}

/* destructor */
BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

/* member functions */
void BitcoinExchange::loadData(std::string input)
{
    std::ifstream file(input.c_str());
    /* input file check */
    if (!file.is_open())
        throw std::runtime_error("Error: Fail to load data.csv\n");
    /* parse input into map container */ 
    std::string line;
    // skip the first line
    std::getline(file, line);
    // start parsing
    while (std::getline(file, line))
    {
        size_t delimiterPos = line.find(",");
        if (delimiterPos != line.npos)
        {
            std::string date = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 1, line.npos);
            double value = atof(valueStr.c_str());
            btcRate[date] = value;
        }
        else
            std::cerr << "Error: invalid line.\n";
    }
    file.close();
}

/* getter */
const std::map<std::string, double>& BitcoinExchange::getMap() const
{
    return btcRate;
}

/* setter */  

/* debugger */
void printMap(const std::map<std::string, double>& map)
{
    std::map<std::string, double>::const_iterator it;
    for (it = map.begin(); it != map.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}

