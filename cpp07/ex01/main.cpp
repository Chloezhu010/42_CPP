/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:57:44 by chloe             #+#    #+#             */
/*   Updated: 2025/06/18 22:43:00 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    increment(int& x)
{
    x += 1;
}

void    ft_toupper(char &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

int main()
{
    int nums[] = {1, 3, 45, 2, 23};
    char chars[] = {'a', 'b', 'c', 'd'};
    size_t len = 5;

    /* iter on numbers */
    iter(nums, 5, increment);
    for (size_t i = 0; i < len; i++)
        std::cout << nums[i] << " ";
    /* iter on strings */
    iter(chars, len, ft_toupper);
    for (size_t i = 0; i < len; i++)
        std::cout << chars[i] << " ";

    return (0);
}