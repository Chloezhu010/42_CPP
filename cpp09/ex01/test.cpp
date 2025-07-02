#include "RPN.hpp"

int main()
{   
    std::string input = "  7 7 + 8 9 -";

    std::istringstream iss(input);
    std::string token;
    while (iss >> token)
        std::cout << "output: " << token << "\n";

    std::string input2 = " 9a ";
    std::istringstream ass(input2);
    int nb;
    char leftover;

    if (!(ass >> nb))
        std::cout << "error\n";
    std::cout << nb << "\n";
    if (ass >> leftover)
        std::cout << "error\n";
       
}