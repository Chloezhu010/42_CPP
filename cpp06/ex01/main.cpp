/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:10:41 by czhu              #+#    #+#             */
/*   Updated: 2025/06/17 21:46:57 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d = {1, "chloe", 42.1};
    Data d2 = {2, "john", 42.2};
    
    /* d */
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Raw: " << raw << std::endl;
    
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Id: " << ptr->id
                << "\nName: " << ptr->name
                << "\nValue: " << ptr->value
                << std::endl;
    
    /* d2 */
    uintptr_t raw2 = Serializer::serialize(&d2);
    std::cout << "Raw: " << raw2 << std::endl;
    
    Data* ptr2 = Serializer::deserialize(raw2);
    std::cout << "Id: " << ptr2->id
                << "\nName: " << ptr2->name
                << "\nValue: " << ptr2->value
                << std::endl;
    
}