/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:04 by czhu              #+#    #+#             */
/*   Updated: 2025/06/02 13:15:32 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "---Constructors---\n";
    // const Animal a;
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n---Get type---\n";
    // std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\n---Make sound---\n";
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();

    std::cout << "\n---Destructors---\n";
    // delete meta;
    delete i;
    delete j;

    // std::cout << "---Constructors WrongAnimal WrongCat---\n";
    // const WrongAnimal* meta2 = new WrongAnimal();
    // const WrongAnimal* i2 = new WrongCat();

    // std::cout << "\n---Get type WrongAnimal WrongCat---\n";
    // std::cout << meta2->getType() << " " << std::endl;
    // std::cout << i2->getType() << " " << std::endl;

    // std::cout << "\n---Make sound WrongAnimal WrongCat---\n";
    // i2->makeSound();
    // meta2->makeSound();

    // std::cout << "\n---Destructors---\n";
    // delete meta2;
    // delete i2;

    return 0;
}