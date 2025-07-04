/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:23:02 by chloe             #+#    #+#             */
/*   Updated: 2025/07/04 17:51:22 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    /* input parsing */
    PmergeMe pm;
    pm.parseInput(ac, av);
    /* debug */
    std::cout << "\n---Debug: before---\n";
    pm.printVec();
    pm.printDeq();

    pm.sortVec();
    pm.sortDeq();

    return (0);
}