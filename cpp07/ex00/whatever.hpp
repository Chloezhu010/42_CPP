/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:58:36 by chloe             #+#    #+#             */
/*   Updated: 2025/06/18 21:40:47 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>

void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>

const T& min(const T& a, const T& b)
{
    if (a < b)
        return (a);
    if (a >= b)
        return (b);
}

template <typename T>

const T& max(const T& a, const T& b)
{
    if (a < b)
        return (b);
    if (a >= b)
        return (a);
}

template <typename T>

T add(T a, T b)
{
    return (a + b);
}