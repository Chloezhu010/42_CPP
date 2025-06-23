/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:08:45 by chloe             #+#    #+#             */
/*   Updated: 2025/06/23 18:16:50 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* construction with no parameter */
template <typename T>
Array<T>::Array(): _data(nullptr), _size(0) {}

/* construction with an unsigned int as a parameter
    - allocate memory for n elements of type T
    - () ensures value initialization
*/
template <typename T>
Array<T>::Array(unsigned int n): _data(new T[n]()), _size(n) {}

/* construction by copy
    - allocate a new internal array with the same size
    - copy each item from src to the new array
    - avoid shallow copaying (don't share the same ptr)
*/
template <typename T>
Array<T>::Array(const Array<T>& other): _data(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

/* construction by assignment operator */
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return (*this);
}

/* operator[] */
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index is out of bounds\n");
    return (_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index is out of bounds\n");
    return (_data[index]);
}

/* destructor */
template <typename T>
Array<T>::~Array()
{
    std::cout << "Destructor called\n";
    delete[] _data;
}

/* member function */
template <typename T>
unsigned int Array<T>::size() const 
{
    return (_size);
}

/* debug functions */
template <typename T>
void    Array<T>::printArray() const
{
    for (unsigned int i = 0; i < this->_size; i++)
        std::cout << this->_data[i] << std::endl;
}