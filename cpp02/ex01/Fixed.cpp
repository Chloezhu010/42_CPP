/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:59:02 by czhu              #+#    #+#             */
/*   Updated: 2025/05/23 17:08:52 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8; 

/* default constructor, init the fixed-point nbr value to 0 */
Fixed::Fixed(): _value(0)
{
    std::cout << "Fixed: Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Fixed: Int constructor called" << std::endl;
    _value = value << _bits; // shift left by 8 bits
    // this->_value = value << this->_bits; // shift left by 8 bits
}

Fixed::Fixed(const float value)
{
    std::cout << "Fixed: Float constructor called" << std::endl;
    _value = roundf(value * (1 << _bits)); // shift left by 8 bits
}

/* copy constructor
    - create a new object by copying data from the existing one
*/
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Fixed: Copy constructor called" << std::endl;
    *this = other;
}

/* overload operator: define how "=" works for the Fixed class
    - return a reference to the current object
    - this: a ptr to the current object
    - &other: address of the source object
    - check and avoid self-assignment
    - retrieve other's interal _value using the getter
    - store the value in this->_value
*/
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Fixed: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

/* default destructor */
Fixed::~Fixed()
{
    std::cout << "Fixed: Destructor called" << std::endl;
}


/* getter
    - return the raw value of the fixed-point value
*/
int     Fixed::getRawBits(void) const
{
    std::cout << "Fixed: getRawBits member function called\n";
    return (this->_value);    
}

/* setter
    - set the raw value of the fixed-point nbr
*/
void    Fixed::setRawBits(int const raw)
{
    std::cout << "Fixed: setRawBits member function called\n";
    this->_value = raw;
}

/* function to convert nbr to float
    - float 3.25
    - represented value: 3.25 * 256 = 832
    - convert to float: 832 / 256
*/
float   Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _bits));
}

/* function to convert nbr to float
    - float 3.25
    - represented value: 3.25 * 256 = 832
    - convert to int: 832 >> 8 = 3
*/
/* function to convert float to int */
int     Fixed::toInt(void) const
{
    return (_value >> _bits);
}

/* overload of << operator */
std::ostream    &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}