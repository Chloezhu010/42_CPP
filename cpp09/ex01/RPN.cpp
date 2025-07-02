/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <czhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:51:07 by chloe             #+#    #+#             */
/*   Updated: 2025/07/02 15:01:27 by czhu             ###   ########.fr       */
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
/* check number
    - valid: return 1
    - invalid: return 0
*/
int RPN::isValidNumber(const char &c)
{ 
    if (c >= 48 && c<= 57)
        return (1);
    return (0);
}

/* check operator
    - valid: return 1
    - invalid: return 0
*/
int RPN::isValidOperator(const char &c)
{
    if (c == '-' || c == '+' || c == '*' || c == '/')
        return (1);
    return (0);
}

/* check space
    - is space: return 1
    - not space: return 0
*/
static int isSpace(char c)
{
    if (c == 32 || (c >= 7 && c <= 13 ))
        return (1);
    return (0);
}

void RPN::processToken(const std::string &input)
{
    int i = 0;
    /* start process input str */
    while (input[i])
    {
        // skip space
        while (isSpace(input[i]))
            i++;
        // check nb
        if (isValidNumber(input[i]))
        {
            // convert the nbr into int
            int nb = input[i] - 48;
            // push to the stack
            _stack.push(nb);
        }
        // check operator
        else if (isValidOperator(input[i]))
            std::cout << input[i] << std::endl; // debug
        else
            std::cerr << "Error: Invaid input\n";
        i++;
    } 
}

/* member functions */
// void RPN::evaluate(const std::string &input)
// {
    
// }

/* getter */

/* setter */  

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