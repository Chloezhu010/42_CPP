/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:10 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 14:26:27 by czhu             ###   ########.fr       */
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
        
        int isValidNumber(const char &c);
        int isValidOperator(const char &c);
        
    public:
        /* constructors */
        RPN();               
        RPN(const RPN& other);
        
        /* operator overload */
        RPN& operator=(const RPN& other);
        
        /* destructor */
        ~RPN();

        /* member functions */
        void processToken(const std::string &input);
        void evaluate(const std::string &input);

        /* getter */

        /* setter */

        /* debug function */
        void printStack();
};

#endif
