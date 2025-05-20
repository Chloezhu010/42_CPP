/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:58:53 by czhu              #+#    #+#             */
/*   Updated: 2025/05/20 12:58:55 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        // Add member variables here
    public:
        Fixed();                              // Default constructor
        Fixed(const Fixed& other);    // Copy constructor
        Fixed& operator=(const Fixed& other); // Copy assignment
        ~Fixed();                             // Destructor
};

#endif
