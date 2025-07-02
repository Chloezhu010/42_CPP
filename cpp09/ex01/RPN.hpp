/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:10 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 21:56:26 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack> // for stack
#include <string>
#include <sstream> // for istringstream
#include <stdexcept> // for runtime_error

class RPN
{
    private:
        std::stack<int> _stack;

        /* utility functions */
        int isValidNumber(const std::string &token);
        int isValidOperator(const std::string &token);
        void applyOperator(const std::string &op);
        void processToken(const std::string &input);
        
    public:
        /* constructors */
        RPN();               
        RPN(const RPN& other);
        
        /* operator overload */
        RPN& operator=(const RPN& other);
        
        /* destructor */
        ~RPN();

        /* member functions */
        int evaluate(const std::string &input);

        /* debug function */
        void printStack();
};

#endif
