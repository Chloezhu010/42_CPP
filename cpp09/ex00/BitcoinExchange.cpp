/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:41 by chloe             #+#    #+#             */
/*   Updated: 2025/06/26 21:58:44 by chloe            ###   ########.fr       */
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
        // Copy member variables
    }
    return *this;
}

/* destructor */
BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

