/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:59:02 by czhu              #+#    #+#             */
/*   Updated: 2025/05/23 11:12:32 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8; 

/* default constructor, init the fixed-point nbr value to 0 */
Fixed::Fixed(): _value(0)
{
    std::cout << "Fixed: Default constructor called" << std::endl;
}

/* copy constructor
    - create a new object by copying data from the existing one
*/
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Fixed: Copy constructor called" << std::endl;
    *this = other;
}

/* overload operator */
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