/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:58:36 by chloe             #+#    #+#             */
/*   Updated: 2025/06/24 16:21:24 by czhu             ###   ########.fr       */
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

T& min(T& a, T& b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>

T& max(T& a, T& b)
{
    if (a < b)
        return (b);
    return (a);
}

/* const version */
template <typename T>

const T& min(const T& a, const T& b)
{
    if (a < b)
        return (a);
    return (b);
}

template <typename T>

const T& max(const T& a, const T& b)
{
    if (a < b)
        return (b);
    return (a);
}
