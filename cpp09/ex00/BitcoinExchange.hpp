/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:47 by chloe             #+#    #+#             */
/*   Updated: 2025/06/26 21:58:48 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange
{
    private:
        
    public:
        /* constructors */
        BitcoinExchange();               
        BitcoinExchange(const BitcoinExchange& other);
        
        /* operator overload */
        BitcoinExchange& operator=(const BitcoinExchange& other);
        
        /* destructor */
        ~BitcoinExchange();

        /* member functions */

        /* getter */

        /* setter */
};

#endif
