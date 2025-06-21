/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:11:22 by chloe             #+#    #+#             */
/*   Updated: 2025/06/21 23:00:08 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Derived.hpp"

int main()
{
    Base* random;

    // random seeding
    std::srand(time(0));
    // for (int i = 0; i < 10; i++)
    // {
    //     random = generate();
    //     identify(random);
    // }

    random = generate();
    std::cout << "\nIdentify from pointer: \n";
    identify(random);
    std::cout << "\nIdentify from reference: \n";
    identify(*random);

    delete random;
    return (0);
}