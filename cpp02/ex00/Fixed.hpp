/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:58:53 by czhu              #+#    #+#             */
/*   Updated: 2025/05/23 11:00:18 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _value; // store the fixed-point number value
        static const int    _bits; // store the number of fractional bits

    public:
        Fixed(); // Default constructor
        Fixed(const Fixed& other); // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment
        ~Fixed(); // Destructor
        
        int     getRawBits(void) const; // return the raw value of the fixed-point value
        void    setRawBits(int const raw); // set the raw value of the fixed-point nbr

};

#endif
