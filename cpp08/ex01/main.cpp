/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:31:12 by chloe             #+#    #+#             */
/*   Updated: 2025/06/22 14:41:32 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib> // for rand()
#include <ctime> // for time()

int main()
{
    std::cout << "--- Original test ---\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    // /* test exceed max size case */
    // try{
    //     sp.addNumber(12);
    // } catch (std::exception& e)
    // {
    //     std::cerr << e.what();
    // }

    /* test shortest, longest span */
    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;   
    } catch (std::exception& e)
    {
        std::cerr << e.what();
    }

    std::cout << "\n--- Adding 1000 random values in one call ---\n";
    std::srand(std::time(0)); // seed random nb generator
    // create a vector of 1000 random ints
    std::vector<int> randData;
    int size = 1000;
    for (int i = 0; i < size; i++)
        randData.push_back(std::rand() % 100); // value 0-99
    // print the values
    for (std::vector<int>::iterator it = randData.begin(); it != randData.end(); it++)
        std::cout << *it << " ";
    // create a span with 1000 capacity
    Span sp2 = Span(size);
    // add randData into sp2 in one call
    try {
        sp2.addNumber(randData.begin(), randData.end());
    } catch(std::exception& e)
    {
        std::cerr << e.what();
    }
    // test shortest, longest span
    try {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;   
    } catch (std::exception& e)
    {
        std::cerr << e.what();
    }

    // std::cout << "\n--- Test copy constructor ---\n";
    // Span b(sp);
    // try {
    //     std::cout << b.shortestSpan() << std::endl;
    //     std::cout << b.longestSpan() << std::endl;   
    // } catch (std::exception& e)
    // {
    //     std::cerr << e.what();
    // }
    
    // std::cout << "\n--- Test copy assignment operator ---\n";
    // Span c;
    // c = sp;
    // try {
    //     std::cout << c.shortestSpan() << std::endl;
    //     std::cout << c.longestSpan() << std::endl;   
    // } catch (std::exception& e)
    // {
    //     std::cerr << e.what();
    // }

    return 0;
}