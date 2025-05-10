/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:04:54 by chloe             #+#    #+#             */
/*   Updated: 2025/05/10 17:39:39 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// constructor
PhoneBook::PhoneBook()
{
    contactCount = 0;
    oldestIndex = 0;
}

// destructor
PhoneBook::~PhoneBook()
{
}

/* add new contact with input validation */
void    PhoneBook::addContact()
{
    std::string input;
    int         index;

    // only keep max 8 contacts
    if (contactCount < 8)
        index = contactCount;
    else
        index = oldestIndex;
    // start collecting contact info
    std::cout << "=== Adding new contact===" << std::endl;
    while (true)
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(0);
        if (contacts[index].setFirstName(input))
            break ;
        std::cout << "Error: Cannot be empty" << std::endl;
    }
    while (true)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(0);
        if (contacts[index].setLastName(input))
            break ;
        std::cout << "Error: Cannot be empty" << std::endl;
    }
    while (true)
    {
        std::cout << "Enter nick name: ";
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(0);
        if (contacts[index].setNickName(input))
            break ;
        std::cout << "Error: Cannot be empty" << std::endl;
    }
    while (true)
    {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(0);
        if (contacts[index].setPhoneNumber(input))
            break ;
        std::cout << "Error: Cannot be empty" << std::endl;
    }
    while (true)
    {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(0);
        if (contacts[index].setDarkSecret(input))
            break ;
        std::cout << "Error: Cannot be empty" << std::endl;
    }
    // set the contact as initialized and update counter
    contacts[index].setInitialized(true);
    if (contactCount < 8)
        contactCount++;
    oldestIndex = (oldestIndex + 1) % 8;
    std::cout << "=== Successfully added new contact===" << std::endl;
}

/* display the summary header */
void PhoneBook::displayHeader()
{
    std::cout << std::setw(10) << "index" << "|"
            << std::setw(10) << "first name" << "|"
            << std::setw(10) << "last name" << "|"
            << std::setw(10) << "nick name" << "|"
            << std::endl;
}

/* display the list of available contacts */
void    PhoneBook::displayContact()
{
    int i;

    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty. Add contact first." << std::endl;
        return ;
    }
    // display header
    displayHeader();
    // display contact rows
    for (i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << contacts[i].displayColumn(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << contacts[i].displayColumn(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << contacts[i].displayColumn(contacts[i].getNickName()) << "|";
        std::cout << std::endl;
    }
}

/* search and display a contact full info by index */
void    PhoneBook::searchContact()
{
    std::string input;
    int         index;
    
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty. Add contact first." << std::endl;
        return ;
    }
    // display all available
    displayContact();
    // get and validate index input
    while (true)
    {
        std::cout << "Enter the index of the contact: ";
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(0);
        // create an input string stream object that reads from the input
        std::istringstream iss(input);
        if (!(iss >> index) || index < 1 || index > contactCount || !iss.eof())
        {
            std::cout << "Error: invalid index. Please enter an valid index." << std::endl;
            continue ;
        }
        break;
    }
    // display the selected contact full info
    contacts[index - 1].displayFullInfo();
}

// // testing
// int main()
// {
//     PhoneBook phonebook;
//     phonebook.addContact();
//     phonebook.displayContact();
//     phonebook.searchContact();
//     return (0);
// }