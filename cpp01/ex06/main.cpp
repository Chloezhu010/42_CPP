/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:13:27 by chloe             #+#    #+#             */
/*   Updated: 2025/05/17 14:11:16 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    std::string level;
    
    // input check
    if (ac != 2)
    {
        std::cout << "Usage: " << av[0] << " <log_level>" << std::endl;
        return (1);
    }
    // output based on the level
    level = av[1];
    harl.complain(level);
    return (0);
}