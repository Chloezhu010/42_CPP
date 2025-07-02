/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:22:07 by chloe             #+#    #+#             */
/*   Updated: 2025/06/26 14:13:26 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::cout << "--- Test vector container---\n";
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);
    // const std::vector<int> nums;

    easyfind(nums, 40);

    std::cout << "--- Test list container---\n";
    std::list<int> lists;
    lists.push_back(10);
    lists.push_back(20);
    lists.push_back(30);
    lists.push_back(40);
    
    easyfind(lists,40);

    return (0);
}