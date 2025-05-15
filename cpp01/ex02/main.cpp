/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:21:05 by chloe             #+#    #+#             */
/*   Updated: 2025/05/15 15:43:13 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // print memory address
    std::cout << "Memory address of the str: " << &str << std::endl;
    std::cout << "Memory address of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address of the stringREF: " << &stringREF << std::endl;
    
    // print value
    std::cout << "Value of the str var: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    
    return (0);
}