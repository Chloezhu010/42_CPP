/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:38:45 by chloe             #+#    #+#             */
/*   Updated: 2025/06/23 18:55:16 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "---Test MutantStack---\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // return 17

    mstack.pop(); // remove 17
    std::cout << mstack.size() << std::endl; // return 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n---Test std::list---\n";
    std::list<int> nums;
    nums.push_back(5);
    nums.push_back(17);
    std::cout << nums.back() << std::endl;

    nums.pop_back();
    std::cout << nums.size() << std::endl;
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(737);
    nums.push_back(0);
    std::list<int>::iterator it2 = nums.begin();
    std::list<int>::iterator ite2 = nums.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    
    return 0;
}