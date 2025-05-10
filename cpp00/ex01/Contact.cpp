/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:01:16 by chloe             #+#    #+#             */
/*   Updated: 2025/05/10 16:45:55 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// constructor
Contact::Contact(void)
{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkSecret = "";
    isInitialized = false;
}

// destructor
Contact::~Contact(void)
{
}

/* helper function to check if the field only has space
    - return true if only has space
    - else return false
*/
bool    onlySpace(std::string str)
{
    size_t i;

    i = 0;
    while (i < str.length())
    {
        if (str[i] != ' ' && str[i] != '\t'
            && str[i] != '\n' && str[i] != '\r')
            return (false);
        i++;
    }
    return (true);
}

// setters
bool    Contact::setFirstName(std::string name)
{
    if (name.empty() || onlySpace(name))
        return (false);
    firstName = name;
    return (true);
}

bool    Contact::setLastName(std::string name)
{
    if (name.empty() || onlySpace(name))
        return (false);
    lastName = name;
    return (true);
}

bool   Contact::setNickName(std::string name)
{
    if (name.empty() || onlySpace(name))
        return (false);
    nickName = name;
    return (true);
}

bool    Contact::setPhoneNumber(std::string nbr)
{
    if (nbr.empty() || onlySpace(nbr))
        return (false);
    phoneNumber = nbr;
    return (true);
}

bool    Contact::setDarkSecret(std::string secret)
{
    if (secret.empty() || onlySpace(secret))
        return (false);
    darkSecret = secret;
    return (true);
}

// getters
std::string Contact::getFirstName()
{
    return (firstName);
}

std::string Contact::getLastName()
{
    return (lastName);
}

std::string Contact::getNickName()
{
    return (nickName);
}

std::string Contact::getPhoneNumber()
{
    return (phoneNumber);
}

std::string Contact::getDarkSecret()
{
    return (darkSecret);
}

// display functions
/* helper function to display col with max 10 char */
std::string Contact::displayColumn(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return (str);        
}

/* display the full info of a selected contact */
void    Contact::displayFullInfo()
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkSecret << std::endl;
}

// utilities
/* considered empty if all fields are empty */
bool    Contact::isEmpty() const
{
    return (firstName.empty() && lastName.empty() && nickName.empty()
        && phoneNumber.empty() && darkSecret.empty());
}

/* considred complete if no fields are empty */
bool    Contact::isComplete() const
{
    return (!firstName.empty() && !lastName.empty() && !nickName.empty()
        && !phoneNumber.empty() && !darkSecret.empty());
}

/* set a contact as initialized after all fields filled */
void    Contact::setInitialized(bool value)
{
    isInitialized = value;
}

/* return the init status of the contact */
bool    Contact::getInitialized()
{
    return (isInitialized);
}

