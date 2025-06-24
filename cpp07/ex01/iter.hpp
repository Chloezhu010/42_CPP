/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:58:00 by chloe             #+#    #+#             */
/*   Updated: 2025/06/24 16:22:41 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

void iter(T* array, size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len; i++)
    {
        func(array[i]);
    }
}

// const version
template <typename T>

void iter(const T* array, size_t len, void (*func)(const T&))
{
    for (size_t i = 0; i < len; i++)
    {
        func(array[i]);
    }
}

template <typename T>

void printItem(T& item)
{
    std::cout << item << std::endl;
}