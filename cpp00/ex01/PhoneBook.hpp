/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:02:58 by chloe             #+#    #+#             */
/*   Updated: 2025/05/10 17:39:57 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
class PhoneBook
{
    private:
        Contact contacts[8];
        int contactCount;
        int oldestIndex;
    public:
        // contructor & destructor
        PhoneBook();
        ~PhoneBook();
        // add, search, display
        void    addContact();
        void    searchContact();
        void    displayHeader();
        void    displayContact();
};

#endif