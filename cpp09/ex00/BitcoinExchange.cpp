/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:41 by chloe             #+#    #+#             */
/*   Updated: 2025/07/01 20:49:24 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* default constructor */
BitcoinExchange::BitcoinExchange()
{
    // std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

/* copy constructor */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    // std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    // std::cout << "BitcoinExchange: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->btcRate = other.btcRate;
    }
    return *this;
}

/* destructor */
BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

/* utility functions */
bool BitcoinExchange::isValidDate(const std::string& date)
{
    // initial check
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    // extract year, month, day substr
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    // check year
    std::istringstream yss(yearStr);
    double year;
    bool validYear = false;
    if (yss >> year)
        validYear = true;
    // check month
    std::istringstream mss(monthStr);
    double month;
    bool validMonth = false;
    if ((mss >> month) && month >= 1 && month <= 12)
        validMonth = true;
    // check day
    std::istringstream dss(dayStr);
    double day;
    bool validDay = false;
    if ((dss >> day) && (day >= 1 && day <= 31))
        validDay = true;
    // check Feb
    bool checkFeb = false;
    if ((static_cast<int>(year) % 4 == 0 && (day >= 0 && day <= 29))
        || (static_cast<int>(year) % 4 != 0 && (day >= 0 && day <= 28)))
        checkFeb = true;
    // final validation
    bool res = validYear && validMonth && validDay;
    if (month == 2)
        res = res && checkFeb;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        res = res && (day <= 30);
    return (res);
}

/* check value, return
    - valid: 0
    - not positive: 1
    - too large: 2
    - not a nbr: 3
*/
int BitcoinExchange::isValidValue(const std::string& valueStr)
{
    // check if can convert to double
    std::istringstream iss(valueStr);
    double value;
    if (iss >> value)
    {
        // check if positive and under 1000
        if (value >= 0 && value <= 1000)
            return (0);
        else if (value < 0)
            return (1);
        else if (value > 1000)
            return (2);
    }
    return (3);
}

/* member functions */
void BitcoinExchange::loadData(std::string input)
{
    std::ifstream file(input.c_str());
    /* file check */
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

double BitcoinExchange::findPrice(std::string date)
{
    std::map<std::string, double>::iterator it;
    // it = btcRate.find(date);
    it = btcRate.lower_bound(date);
    // exact match
    if (it != btcRate.end() && it->first == date)
        return (it->second);
    // before 2009-01-02
    else if (it == btcRate.begin())
        return (-1);
    // not exact match, step back to the closest earlier date
    else if (it != btcRate.end() && it->first != date)
    {
        it--;
        return (it->second);
    }
    // no match in the database
    else
        return (-1);
}

void BitcoinExchange::processInput(std::string filename)
{
    std::ifstream file(filename.c_str());
    /* file check */
    if (!file.is_open())
        throw std::runtime_error("Error: Fail to load input file\n");
    /* process line by line, check date & value */
    std::string line;
    // skip the header line
    std::getline(file, line);
    // start processing
    while (std::getline(file, line))
    {
        size_t delimiterPos = line.find(" | ");
        if (delimiterPos != line. npos)
        {
            std::string date = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 3, line.npos);
            // check date
            if (isValidDate(date) == false)
                std::cout << "Error: bad input => " << date << std::endl;
            // check value
            if (isValidValue(valueStr) == 1)
                std::cout << "Error: not a positive number\n";
            else if (isValidValue(valueStr) == 2)
                std::cout << "Error: too large a number\n";
            else if (isValidValue(valueStr) == 3)
                std::cout << "Error: not a number\n";
            // both valid
            if (isValidDate(date) && isValidValue(valueStr) == 0)
            {
                double value = atof(valueStr.c_str());
                double price = findPrice(date);
                double result = price * value;
                if (price < 0)
                    std::cout << "Error: date out of range\n";
                else
                    std::cout << date << " => " << valueStr << " = " << result << std::endl;
            }
        }
        else
            std::cerr << "Error: invalid line\n";
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

