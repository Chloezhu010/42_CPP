/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:10:48 by czhu              #+#    #+#             */
/*   Updated: 2025/06/17 14:10:49 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* default constructor */
Serializer::Serializer()
{
    std::cout << "Serializer: Default constructor called" << std::endl;
}

/* copy constructor */
Serializer::Serializer(const Serializer& other)
{
    std::cout << "Serializer: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Serializer& Serializer::operator=(const Serializer& other)
{
    std::cout << "Serializer: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
Serializer::~Serializer()
{
    std::cout << "Serializer: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

