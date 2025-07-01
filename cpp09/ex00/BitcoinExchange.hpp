/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:47 by chloe             #+#    #+#             */
/*   Updated: 2025/06/30 22:56:40 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map> // for std::map
#include <fstream> // for ifstream
#include <string> // for getline
#include <stdexcept>
#include <cstdlib> // for atof
#include <sstream> // for istringstream

class BitcoinExchange
{
    private:
        std::map<std::string, double> btcRate;
        /* utility functions */
        bool isValidDate(const std::string& date);
        int isValidValue(const std::string& valueStr);
        
    public:
        /* constructors */
        BitcoinExchange();               
        BitcoinExchange(const BitcoinExchange& other);
        
        /* operator overload */
        BitcoinExchange& operator=(const BitcoinExchange& other);
        
        /* destructor */
        ~BitcoinExchange();

        /* member functions */
        void loadData(std::string input);
        void processInput(std::string filename);
        double findPrice(std::string date);

        /* getter */
        const std::map<std::string, double>& getMap() const;

        /* setter */

};

/* debug function */
void printMap(const std::map<std::string, double>& map);

#endif
