/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:58:47 by chloe             #+#    #+#             */
/*   Updated: 2025/06/29 14:32:24 by czhu             ###   ########.fr       */
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
