/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:58:53 by czhu              #+#    #+#             */
/*   Updated: 2025/05/23 20:54:18 by chloe            ###   ########.fr       */
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

    /* operator */
        Fixed& operator=(const Fixed& other);
        /* comparison operators */
        bool   operator< (const Fixed &other) const;
        bool   operator> (const Fixed &other) const;
        bool   operator>=(const Fixed &other) const;
        bool   operator<=(const Fixed &other) const;
        bool   operator==(const Fixed &other) const;
        bool   operator!=(const Fixed &other) const;
        
        /* arithmetic operators */
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        /* pre-increment operators */
        Fixed &operator++(); // prefix ++a
        Fixed &operator--(); // prefix --a

        /* post-increment operators */
        Fixed operator++(int); // postfix a++
        Fixed operator--(int); // postfix a--

        /* min max */
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        
    /* destructor */
        ~Fixed(); // Destructor
        
    /* public methods */
        float   toFloat(void) const;
        int     toInt(void) const;

    /* getter & setter */
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

/* overload for output stream */
std::ostream    &operator<<(std::ostream &out, const Fixed &fixed);

#endif
