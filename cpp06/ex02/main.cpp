/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:11:22 by chloe             #+#    #+#             */
/*   Updated: 2025/06/18 17:48:28 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Derived.hpp"

int main()
{
    Base* random;

    random = generate();
    
    std::cout << "\nIdentify from pointer: \n";
    identify(random);
    std::cout << "\nIdentify from reference: \n";
    identify(*random);

    delete random;
    return (0);
}