/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:10 by chloe             #+#    #+#             */
/*   Updated: 2025/07/01 23:14:55 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack> // for stack
#include <string>
#include <sstream> // for istringstream

class RPN
{
    private:
        std::stack<int> _stack;

        /* utility functions */
        void processToken(const std::string &token);
        int isValidNumber(const std::string &token);
        int isValidOperator(const std::string &token);
        
    public:
        /* constructors */
        RPN();               
        RPN(const RPN& other);
        
        /* operator overload */
        RPN& operator=(const RPN& other);
        
        /* destructor */
        ~RPN();

        /* member functions */
        void evaluate(const std::string &input);

        /* getter */

        /* setter */
};

#endif
