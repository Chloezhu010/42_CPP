/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:59:52 by chloe             #+#    #+#             */
/*   Updated: 2025/06/19 13:51:57 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

int main()
{   
    /* construct without size */
    Array<int> a;
    /* construct with size */
    Array<int> b(4);
    /* modify b array value */
    try {
        b[0] = 1;
        b[1] = 2;
        b[2] = 3;
        b[3] = 4;
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    /* copy construct */
    Array<int> c(b);
    /* copy assignment */
    Array<int> d;
    d = c;

    std::cout << "Array a size: " << a.size() << std::endl;
    a.printArray();
    std::cout << "Array b size: " << b.size() << std::endl;
    b.printArray();
    std::cout << "Array c size: " << c.size() << std::endl;
    c.printArray();
    std::cout << "Array d size: " << d.size() << std::endl;
    d.printArray();
    
    /* modify c array value */
    std::cout << "\nModify c array value\n";
    try {
        c[0] = 99;
        c[1] = 98;
        c[2] = 97;
        c[3] = 96;
        /* test out of bound index */
        c[4] = 95;
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    c.printArray();
    b.printArray();
    d.printArray();
    /* modify d array value */
    std::cout << "\nModify d array value\n";
    try {
        d[0] = 199;
        d[1] = 198;
        d[2] = 197;
        d[3] = 196;
        /* test out of bound index */
        d[4] = 195;
    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    c.printArray();
    b.printArray();
    d.printArray();
}