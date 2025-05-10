/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:49:05 by chloe             #+#    #+#             */
/*   Updated: 2025/05/10 17:10:12 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

/* display usage */
void    displayUsage()
{
    std::cout << "\nEnter command (ADD, SEARCH, or EXIT): ";
}

int main()
{
    PhoneBook   phonebook;
    std::string cmd;

    while (true)
    {
        displayUsage();
        // get cmd input from user
        if (!std::getline(std::cin, cmd) || std::cin.eof())
        {
            std::cout << "Please enter command" << std::endl;
            break ;
        }
        // process cmd
        if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else if (cmd == "EXIT")
            break ;
        else
            std::cout << "Error: Unknown command." << std::endl;
    }
    return (0);
}