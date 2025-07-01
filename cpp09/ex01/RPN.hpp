/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:10 by chloe             #+#    #+#             */
/*   Updated: 2025/07/01 23:08:26 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack> // for stack
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;

        void processToken(std::string &input);
        
    public:
        /* constructors */
        RPN();               
        RPN(const RPN& other);
        
        /* operator overload */
        RPN& operator=(const RPN& other);
        
        /* destructor */
        ~RPN();

        /* member functions */

        /* getter */

        /* setter */
};

#endif
