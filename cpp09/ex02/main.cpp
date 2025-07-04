/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:23:02 by chloe             #+#    #+#             */
/*   Updated: 2025/07/04 21:26:22 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    /* input parsing */
    PmergeMe pm;
    int res = pm.parseInput(ac, av);
    if (res != -1)
    {
        /* show before after */
        std::cout << "Before: ";
        pm.printVec();
        std::cout << "After: ";
        pm.sortVec();
        pm.sortDeq();
        /* performance benchmark */
        
    }

    return (0);
}