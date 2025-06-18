/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Derived.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:32:56 by chloe             #+#    #+#             */
/*   Updated: 2025/06/18 17:46:43 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Derived.hpp"

Base*   generate(void)
{
    // random seeding
    std::srand(time(0));
    // array of class ptrs
    Base* array[3];
    array[0] = new A();
    array[1] = new B();
    array[2] = new C();
    // randomly return between ABC
    if (std::rand() % 3 == 0)
        return (array[0]);
    else if (std::rand() % 3 == 1)
        return (array[1]);
    else
        return (array[2]);
}

/* when casting fails, returns nullptr */
void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is an A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "This is an B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "This is an C\n";
    else
        std::cerr << "Error: Unknown type\n";
}

/* when casting fails, throw exception */
void    identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "This is an A\n";
    } catch (std::exception& e)
    {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "This is an B\n";
        } catch (std::exception& e)
        {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "This is an C\n";
            } catch (std::exception& e)
            {
                std::cerr << "Error: Unknown type\n";
            }
        }
    }
}