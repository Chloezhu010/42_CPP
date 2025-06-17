/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:10:33 by czhu              #+#    #+#             */
/*   Updated: 2025/06/17 16:23:41 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

// need to be abstract
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
        ~Serializer();

        /* member functions */
        static uintptr_t seralize(Data* ptr);
        static Data* deseralize(uintptr_t raw);

        /* getter */

        /* setter */
};

#endif
