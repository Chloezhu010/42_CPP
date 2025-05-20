/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:59:02 by czhu              #+#    #+#             */
/*   Updated: 2025/05/20 12:59:06 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Fixed: Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Fixed: Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Fixed: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Fixed: Destructor called" << std::endl;
}
