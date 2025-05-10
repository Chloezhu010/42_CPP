/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:01:22 by chloe             #+#    #+#             */
/*   Updated: 2025/05/10 16:42:19 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

/* contact class to store individual contact info */
class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkSecret;
        bool        isInitialized;
    public:
        // contructor & destructor
        Contact();
        ~Contact();
        
        // setters
        bool    setFirstName(std::string name);
        bool    setLastName(std::string name);
        bool    setNickName(std::string name);
        bool    setPhoneNumber(std::string nbr);
        bool    setDarkSecret(std::string secret);

        // getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkSecret();

        // display
        std::string displayColumn(const std::string &str) const;
        void    displayFullInfo();

        // utilities
        bool    isEmpty() const;
        bool    isComplete() const;
        void    setInitialized(bool value);
        bool    getInitialized();
};

#endif