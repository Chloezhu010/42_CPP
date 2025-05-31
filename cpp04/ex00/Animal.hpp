/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:28:59 by czhu              #+#    #+#             */
/*   Updated: 2025/05/31 14:45:14 by chloe            ###   ########.fr       */
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
        virtual ~Animal();
        
        /* member functions */
        virtual void    makeSound() const;
        
        /* getter */
        std::string    getType() const;

        /* setter */
};

#endif
