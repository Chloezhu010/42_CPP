/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:58:53 by czhu              #+#    #+#             */
/*   Updated: 2025/05/23 17:08:54 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _value; // store the fixed-point number value
        static const int    _bits; // store the number of fractional bits

    public:
        /* constructor */
        Fixed(); // default
        Fixed(const int value); // int to fixed
        Fixed(const float value); // float to fixed
        Fixed(const Fixed& other); // copy

        /* copy assignment operator */
        Fixed& operator=(const Fixed& other);
        
        /* destructor */
        ~Fixed(); // Destructor
        
        /* public methods */
        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &out, const Fixed &fixed);

#endif
