/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:28:59 by czhu              #+#    #+#             */
/*   Updated: 2025/05/30 16:39:16 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        /* constructors */
        Animal();                              
        Animal(const Animal& other);    
        
        /* operator overload */
        Animal& operator=(const Animal& other); 
        
        /* destructor */
        ~Animal();
        
        /* member functions */
        void    makeSound();
};

class Dog : public Animal
{
    
};

class Cat : public Animal
{
    
};

#endif
