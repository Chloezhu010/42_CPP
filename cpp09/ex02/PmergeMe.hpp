/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:51 by chloe             #+#    #+#             */
/*   Updated: 2025/07/03 18:35:34 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector> // for std::vector
#include <deque> // for std::deque
#include <string>
#include <stdexcept>
#include <sstream> // for istringstream

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        /* utility */
        int isValidNumber(const std::string &token);
        int isDuplicate(int value);
        
    public:
        /* constructors */
        PmergeMe();               
        PmergeMe(const PmergeMe& other);
        
        /* operator overload */
        PmergeMe& operator=(const PmergeMe& other);
        
        /* destructor */
        ~PmergeMe();

        /* member functions */
        void parseInput(int ac, char **av);

        /* getter */

        /* setter */

        /* debug functions */
        void printVec();
        void printDeq();
};

#endif
