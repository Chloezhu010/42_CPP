#include "RPN.hpp"

int main()
{
    RPN test;
    
    std::string input = "  7 7 + ";
    test.processToken(input);
    test.printStack();    
}