/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:51 by chloe             #+#    #+#             */
/*   Updated: 2025/07/03 22:06:27 by chloe            ###   ########.fr       */
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
        /* insertion order helper */
        std::vector<size_t> getJacobIndice(size_t n);
        /* pair spliting helper */
        std::vector<int> splitPairVec(const std::vector<int> &input, 
                                        std::vector<int> &main, 
                                        std::vector<int> &pend, 
                                        int &leftover);
        std::deque<int> splitPairDeq(const std::deque<int> &input,
                                        std::deque<int> &main,
                                        std::deque<int> &pend,
                                        int &leftover);
        /* core sorting logic helper */
        void binaryInsertVec(std::vector<int> &sorted, int value);
        void binaryInsertDeq(std::deque<int> &sorted, int value);
        void sortVecRecursive(std::vector<int> &data);
        void sortDeqRecursive(std::deque<int> &data);
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
        void sortVec();
        void sortDeq();

        /* getter */

        /* setter */

        /* debug functions */
        void printVec();
        void printDeq();
};

#endif
