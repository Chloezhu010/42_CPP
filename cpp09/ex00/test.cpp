/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:49 by chloe             #+#    #+#             */
/*   Updated: 2025/06/30 20:28:26 by chloe            ###   ########.fr       */
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
    // /* input count check */
    // if (ac != 2)
    // {
    //     std::cerr << "Error: Neet an input file\n";
    //     return (1);
    // }
    // /* input file check */
    // std::ifstream file(av[1]);
    // if (!file.is_open())
    // {
    //     std::cerr << "Error: Failed to open the file\n";
    //     return (1);
    // }
    // // /* DEBUG printout the input file */
    // // std::string line;
    // // while (std::getline(file, line))
    // //     std::cout << line << std::endl;
    
    // /* parse input into map container */
    // std::string line;
    // std::map<std::string, double> btcMap;
    // // skip the first line
    // std::getline(file, line);
    // // start parsing
    // while (std::getline(file, line))
    // {
    //     size_t delimiterPos = line.find(" | ");
    //     // extract the date, value in string
    //     if (delimiterPos != line.npos)
    //     {
    //         std::string date = line.substr(0, delimiterPos);
    //         std::string valueStr = line.substr(delimiterPos + 3, line.npos);
    //         // convert the value from str to float, inset to the map container
    //         std::istringstream iss(valueStr);
    //         double value;
    //         if (iss >> value)
    //         {
    //             if (value < 0)
    //                 std::cout << "Error: not a positive number.\n";
    //             else if (value > 2147483647)
    //                 std::cout << "Error: too large a number.\n";
    //             else
    //                 btcMap.insert(std::make_pair(date, value)); 
    //         }
    //         else
    //             std::cerr << "Error: Invalid value\n";    
    //     }
    //     else
    //         std::cerr << "Error: Invalid line\n";
    // }
    
    // /* DEBUG printout the map key-value */
    // std::map<std::string, double>::const_iterator it;
    // for (it = btcMap.begin(); it != btcMap.end(); it++)
    //     std::cout << it->first << ": " << it->second << std::endl;
    
    // file.close();

    
    std::string date2 = "2025-1-1";
    std::string date3 = "fooo-1-1";

    // std::cout << date.size() << std::endl;
    // std::cout << date2.size() << std::endl;
    // std::cout << date3.size() << std::endl;

    // std::string yearStr = date.substr(0, 4);
    // std::string monthStr = date.substr(5, 2);
    // std::string dayStr = date.substr(8, 2);
    
    // std::cout << yearStr << std::endl;
    // std::cout << monthStr << std::endl;
    // std::cout << dayStr << std::endl;

    std::string date = "2025-42-30";
    // initial check
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error\n";
        return (false);
    }
    // extract year, month, day substr
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    std::cout << yearStr << std::endl;
    std::cout << monthStr << std::endl;
    std::cout << dayStr << std::endl;

    // check year
    std::istringstream yss(yearStr);
    double year;
    bool validYear = false;
    if (yss >> year)
    {
        validYear = true;
        std::cout << "year valid\n";
    }
    // check month
    std::istringstream mss(monthStr);
    double month;
    bool validMonth = false;
    if ((mss >> month) && month >= 1 && month <= 12)
    {
        validMonth = true;
        std::cout << "month valid\n";
    }
    // check day
    std::istringstream dss(dayStr);
    double day;
    bool validDay = false;
    if ((dss >> day) && (day >= 1 && day <= 31))
    {
        validDay = true;
        std::cout << "day valid\n";
    }
    // check month with 30 days
    // bool specialMonth = false;
    // if ((month == 4 || month == 6 || month == 9 || month == 11)
    //     && (day >= 0 && day <= 30))
    // {
    //     specialMonth = true;
    //     std::cout << "special month valid\n";
    // }
    // check Feb
    bool checkFeb = false;
    if ((static_cast<int>(year) % 4 == 0 && (day >= 0 && day <= 29))
        || (static_cast<int>(year) % 4 != 0 && (day >= 0 && day <= 28)))
    {
        checkFeb = true;
        std::cout << "feb valid\n";
    }
    bool res = validYear && validMonth && validDay;
    if (month == 2)
        res = res && checkFeb;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        res = res && (day <= 30);
    else
        res = res && (day <= 31);

    std::cout << "valid or not: " << res << std::endl;

    
    
    return (0);
}