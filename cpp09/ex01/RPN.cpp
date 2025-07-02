/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:07 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 21:56:39 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* default constructor */
RPN::RPN()
{
    // std::cout << "RPN: Default constructor called" << std::endl;
}

/* copy constructor */
RPN::RPN(const RPN& other)
{
    // std::cout << "RPN: Copy constructor called" << std::endl;
    *this = other;
}

/* copy assignment operator */
RPN& RPN::operator=(const RPN& other)
{
    // std::cout << "RPN: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

/* destructor */
RPN::~RPN()
{
    // std::cout << "RPN: Destructor called" << std::endl;
}

/* utility functions */
/* check number with in -10 to 10
    - valid: return 1
    - invalid: return 0
*/
int RPN::isValidNumber(const std::string &token)
{ 
    std::istringstream iss(token);
    int nb;
    char leftover;
    
    if (!(iss >> nb))
        return (0);
    if (iss >> leftover)
        return (0);
    return (nb > -10 && nb < 10);
}

/* check operator
    - valid: return 1
    - invalid: return 0
*/
int RPN::isValidOperator(const std::string &token)
{
    if (token == "-" || token == "+" || token == "*" || token == "/")
        return (1);
    return (0);
}

void RPN::applyOperator(const std::string &op)
{
    // check stack
    if (_stack.size() < 2)
        throw (std::runtime_error("Error"));
    // obtain the top and second nb
    int top = _stack.top();
    _stack.pop();
    int second = _stack.top();
    _stack.pop();
    int res;
    // apply operator
    if (op == "+")
        res = top + second;
    else if (op == "-")
        res = second - top;
    else if (op == "*")
        res = top * second;
    else if (op == "/")
    {
        if (top == 0)
            throw (std::runtime_error("Error: division by zero"));
        res = second / top;
    }
    else
        throw (std::runtime_error("Error: unknown operator"));
    _stack.push(res);    
}

void RPN::processToken(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;
    while (iss >> token)
    {
        // check nbr
        if (isValidNumber(token))
        {
            int nb = atoi(token.c_str());
            _stack.push(nb);            
        }
        // check operator
        else if (isValidOperator(token))
            applyOperator(token);
        else
            throw (std::runtime_error("Error: Invalid input"));
    }
}

/* member functions */
int RPN::evaluate(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;
    while (iss >> token)
        processToken(token);
    if (_stack.size() != 1)
        throw (std::runtime_error("Error"));
    return (_stack.top());
}

/* debug functions */
void RPN::printStack()
{
    std::cout << "Print out from top to bottom: ";
    while(!_stack.empty())
    {
        std::cout << _stack.top() << " ";
        _stack.pop();
    }
    std::cout << std::endl;
}