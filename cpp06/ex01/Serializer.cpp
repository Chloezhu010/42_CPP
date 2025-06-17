/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:10:48 by czhu              #+#    #+#             */
/*   Updated: 2025/06/17 21:43:09 by chloe            ###   ########.fr       */
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
    if (this == &other) {
        return *this;
    }
    return *this;
}

/* destructor */
Serializer::~Serializer()
{
    std::cout << "Serializer: Destructor called" << std::endl;
}

/* member functions */
uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

