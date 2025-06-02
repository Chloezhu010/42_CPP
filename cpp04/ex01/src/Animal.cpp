/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:28:51 by czhu              #+#    #+#             */
/*   Updated: 2025/05/31 15:15:55 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"

/* default constructor */
Animal::Animal()
{
    this->type = "Animal";
    std::cout << "Animal: Default constructor called" << std::endl;
}

/* copy constructor */
Animal::Animal(const Animal& other)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* destructor */
Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

/* member functions */
void    Animal::makeSound() const
{
    std::cout << this->type << " makes a sound!🔊\n";
}

/* getter */
std::string    Animal::getType() const
{
    return (this->type);
}