/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:22:02 by chloe             #+#    #+#             */
/*   Updated: 2025/06/26 14:09:23 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm> // for std::find

template <typename T>

typename T::iterator easyfind(T& container, int target)
{
    typename T::iterator res = std::find(container.begin(), container.end(), target);
    if (res != container.end())
        std::cout << "Found: " << *res << "\n";
    else
        std::cerr << "Not found\n";
    return (res);
}

template <typename T>

typename T::const_iterator easyfind(const T& container, int target)
{
    typename T::const_iterator res = std::find(container.begin(), container.end(), target);
    if (res != container.end())
        std::cout << "Found: " << *res << "\n";
    else
        std::cerr << "Not found\n";
    return (res);
}

#endif