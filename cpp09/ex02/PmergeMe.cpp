/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:59 by chloe             #+#    #+#             */
/*   Updated: 2025/07/03 18:47:15 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* default constructor */
PmergeMe::PmergeMe()
{
    // std::cout << "PmergeMe: Default constructor called" << std::endl;
}

/* copy constructor */
PmergeMe::PmergeMe(const PmergeMe& other)
{
    // std::cout << "PmergeMe: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    // std::cout << "PmergeMe: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

/* destructor */
PmergeMe::~PmergeMe()
{
    // std::cout << "PmergeMe: Destructor called" << std::endl;
}

/* utility */
/* check nb
    - valid: 1
    - invalid: 0
*/
int PmergeMe::isValidNumber(const std::string &token)
{
    std::istringstream iss(token);
    int nb;
    
    if (iss >> nb)
    {
        if (nb > 0)
            return (1);
    }
    return (0);
}

/* check duplication
    - no duplication: 1
    - has duplication: 0
*/
int PmergeMe::isDuplicate(int value)
{
    std::vector<int>::iterator it = _vec.begin();
    while (it != _vec.end())
    {
        if (*it == value)
        {
            return (0);
            break ;
        }
        it++;
    }
    return (1);
}

/* member functions */
void PmergeMe::parseInput(int ac, char **av)
{
    /* input check */
    if (ac <= 2)
        std::cerr << "Error: Need at least two number to sort\n";
    /* parse input */
    for (int i = 1; i < ac; i++)
    {
        if (isValidNumber(av[i]))
        {
            // convert to int
            int nb = atoi(av[i]);
            // check duplication
            if (isDuplicate(nb))
            {
                // push into the containers
                _vec.push_back(nb);
                _deq.push_back(nb);
            }
            else
            {
                std::cerr << "Error: duplicated input\n";
                // clear the containers
                _vec.clear();
                _deq.clear();
                break ;
            }
        }
        else
        {
            std::cerr << "Error: invalid input\n";
            // clear the containers
            _vec.clear();
            _deq.clear();
            break ;
        }
    }
}


/* getter */

/* setter */  

/* debug */
void PmergeMe::printVec()
{
    std::cout << "Print vector: \n";
    std::vector<int>::iterator it = _vec.begin();
    while (it != _vec.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}

void PmergeMe::printDeq()
{
    std::cout << "Print deque: \n";
    std::deque<int>::iterator it = _deq.begin();
    while (it != _deq.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}