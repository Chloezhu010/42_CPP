/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:31:12 by chloe             #+#    #+#             */
/*   Updated: 2025/06/21 15:54:32 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    /* test exceed max size case */
    try{
        sp.addNumber(12);
    } catch (std::exception& e)
    {
        std::cerr << e.what();
    }

    /* test shortest, longest span */
    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;   
    } catch (std::exception& e)
    {
        std::cerr << e.what();
    }
    return 0;
}