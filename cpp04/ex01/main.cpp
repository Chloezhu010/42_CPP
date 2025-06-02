/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:29:04 by czhu              #+#    #+#             */
/*   Updated: 2025/06/02 12:24:56 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Animal.hpp"
#include "incl/Dog.hpp"
#include "incl/Cat.hpp"
#include "incl/Brain.hpp"

void    testConstructorDestructor()
{
    std::cout << "---Constructors & Destructor ---\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
}

void    testCopyConstructor()
{
    std::cout << "\n---Copy constructor---\n";
    Dog dog1;
    dog1.getBrain()->setIdea(0, "chase ball");
    
    Dog dog2(dog1); // invoke copy constructor
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "sleep");
    std::cout << "Dog1 idea[0] after: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0] after: " << dog2.getBrain()->getIdea(0) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdea(0, "play at home");

    Cat cat2(cat1); // invoke copy constructor
    std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;

    cat2.getBrain()->setIdea(0, "eat");
    std::cout << "Cat1 idea[0] after: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea[0] after: " << cat2.getBrain()->getIdea(0) << std::endl;
}

void    testCopyAssignment()
{
    std::cout << "\n---Copy assignment---\n";
    Dog dog1;
    dog1.getBrain()->setIdea(1, "eat food");

    Dog dog2 = dog1; // invoke copy assignment
    std::cout << "Dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Dog2 idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;

    dog2.getBrain()->setIdea(1, "run");
    std::cout << "Dog1 idea[1] after: " << dog1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Dog2 idea[1] after: " << dog2.getBrain()->getIdea(1) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdea(1, "walk around");

    Cat cat2 = cat1; // invoke copy assignment
    std::cout << "Cat1 idea[1]: " << cat1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 idea[1]: " << cat2.getBrain()->getIdea(1) << std::endl;

    cat2.getBrain()->setIdea(1, "go home");
    std::cout << "Cat1 idea[1] after: " << cat1.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat2 idea[1] after: " << cat2.getBrain()->getIdea(1) << std::endl;
}

void    testPolymorphism()
{
    std::cout << "\n---Polymorphism array---\n";
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();
    for (int i = 0; i < size; i++)
        delete animals[i];    
}

int main()
{
    testConstructorDestructor();
    testCopyConstructor();
    testCopyAssignment();
    testPolymorphism();
    
    return 0;
}