/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:59 by chloe             #+#    #+#             */
/*   Updated: 2025/07/04 15:48:02 by chloe            ###   ########.fr       */
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

/* insertion order helper */
std::vector<size_t> PmergeMe::getJacobIndice(size_t n)
{
    std::vector<size_t> result;
       
    if (n == 0)
        return (result);
    /* - generate jacobsthal nbr up to next <= n
       - store it in the jacob container 
    */
    std::vector<size_t> jacob;
    jacob.push_back(0);
    if (n >= 1)
        jacob.push_back(1);
    for (size_t i = 2; ; i++)
    {
        size_t next = jacob[i - 1] + jacob[i - 2] * 2;
        if (n <= next)
            break ;
        jacob.push_back(next);
    }
    /* generate the insertion indice */
    for (size_t j = 2; j < jacob.size(); j++)
        result.push_back(jacob[j]);
    result.push_back(0);
    /* fill in the rest of the indice */
    for (size_t k = 0; k < n; k++)
    {
        std::vector<size_t>::iterator it = std::find(jacob.begin(), jacob.end(), k);
        if (it == jacob.end())
            result.push_back(k);
    }
    return (result);
}

/* pair spliting helper */
void PmergeMe::splitPairVec(const std::vector<int> &input, std::vector<int> &main, 
                                std::vector<int> &pend, int &leftover)
{
    std::vector<int>::const_iterator it = input.begin();
    /* loop through the input numbers */
    while (it + 1 != input.end())
    {
        if (*it > *(it + 1))
        {
            main.push_back(*it);
            pend.push_back(*(it + 1));
        }
        else
        {
            main.push_back(*(it + 1));
            pend.push_back(*it);
        }
        it += 2;
    }
    /* check the last item */
    if (input.size() % 2 != 0)
        leftover = input.back();
    else
        leftover = -1;
}

void PmergeMe::splitPairDeq(const std::deque<int> &input, std::deque<int> &main,
                                std::deque<int> &pend, int &leftover)
{
    std::deque<int>::const_iterator it = input.begin();
    /* loop through the input numbers */
    while (it + 1 != input.end())
    {
        if (*it > *(it + 1))
        {
            main.push_back(*it);
            pend.push_back(*(it + 1));
        }
        else
        {
            main.push_back(*(it + 1));
            pend.push_back(*it);
        }
        it += 2;
    }
    /* check the last item */
    if (input.size() % 2 != 0)
        leftover = input.back();
    else
        leftover = -1;
}

/* binary search & insert */
void PmergeMe::binaryInsertVec(std::vector<int> &sorted, int value)
{
    // find the position to insert
    std::vector<int>::iterator it;
    it = std::lower_bound(sorted.begin(), sorted.end(), value);
    // insert the value
    sorted.insert(it, value);
}

void PmergeMe::binaryInsertDeq(std::deque<int> &sorted, int value)
{
    // find the position to insert
    std::deque<int>::iterator it;
    it = std::lower_bound(sorted.begin(), sorted.end(), value);
    // insert the value
    sorted.insert(it, value);
}

/* recursive sorting */
void PmergeMe::sortVecRecursive(std::vector<int> &data)
{

}

void PmergeMe::sortDeqRecursive(std::deque<int> &data)
{

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