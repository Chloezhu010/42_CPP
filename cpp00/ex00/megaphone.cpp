/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:01:32 by chloe             #+#    #+#             */
/*   Updated: 2025/05/09 17:01:35 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void    print_arg(char *arg)
{
    while (*arg)
    {
        if (std::isalpha(*arg))
            std::cout << (char)std::toupper(*arg);
        else
            std::cout << *arg;
        arg++;
    }
}

int main(int ac, char **av)
{
    int i;
    
    i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[i])
        {
            print_arg(av[i]);
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}