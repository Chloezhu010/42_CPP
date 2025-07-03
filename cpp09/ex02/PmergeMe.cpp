/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:59 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 22:23:00 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* default constructor */
PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe: Default constructor called" << std::endl;
}

/* copy constructor */
PmergeMe::PmergeMe(const PmergeMe& other)
{
    std::cout << "PmergeMe: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    std::cout << "PmergeMe: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe: Destructor called" << std::endl;
}

/* member functions */

/* getter */

/* setter */  

