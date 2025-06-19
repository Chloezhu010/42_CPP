/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:00:07 by chloe             #+#    #+#             */
/*   Updated: 2025/06/19 13:36:59 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream> 

template <typename T>

class Array
{
    private:
        T*              _data;
        unsigned int    _size;
    public:
        /* construction with no parameter */
        Array();
        /* construction with an unsigned int as a parameter */
        Array(unsigned int n);
        /* construction by copy and assignment operator */
        Array(const Array& other);
        Array& operator=(const Array& other);

        /* operator [] */
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        /* destructor */
        ~Array();

        /* member function */
        unsigned int size() const;

        /* debug */
        void printArray() const;
};

#include "Array.tpp"

#endif