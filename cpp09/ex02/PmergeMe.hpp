/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:22:51 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 22:22:51 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe
{
    private:
        
    public:
        /* constructors */
        PmergeMe();               
        PmergeMe(const PmergeMe& other);
        
        /* operator overload */
        PmergeMe& operator=(const PmergeMe& other);
        
        /* destructor */
        ~PmergeMe();

        /* member functions */

        /* getter */

        /* setter */
};

#endif
