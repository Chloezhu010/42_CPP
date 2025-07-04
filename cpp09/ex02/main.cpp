/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:23:02 by chloe             #+#    #+#             */
/*   Updated: 2025/07/04 22:10:49 by chloe            ###   ########.fr       */
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
        std::clock_t start_vec = std::clock();
        pm.sortVec();
        std::clock_t end_vec = std::clock();

        std::clock_t start_deq = std::clock();
        pm.sortDeq();
        std::clock_t end_deq = std::clock();
        /* performance benchmark output */
        double cpu_time_vec = 1000000 * (end_vec - start_vec) / CLOCKS_PER_SEC;
        double cpu_time_deq = 1000000 * (end_deq - start_deq) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << pm.getVec().size()
                    << " elements with std::vector: "
                    << cpu_time_vec << " us\n";
        std::cout << "Time to process a range of " << pm.getDeq().size()
                    << " elements with std::deque: "
                    << cpu_time_deq << " us\n";
    }

    return (0);
}