/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:10:33 by czhu              #+#    #+#             */
/*   Updated: 2025/06/17 21:45:19 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct Data {
    int         id;
    std::string name;
    double       value;
} Data;
class Serializer
{
    private:
        
    public:
        /* constructors */
        Serializer();               
        Serializer(const Serializer& other);
        
        /* operator overload */
        Serializer& operator=(const Serializer& other);
        
        /* destructor */
        virtual ~Serializer() = 0;

        /* member functions */
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
