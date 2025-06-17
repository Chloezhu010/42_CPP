#include <cstdlib>
#include <iostream>
#include <cstring>

int main()
{
    const char *str = "9999999";
    // char* endptr = NULL;

    int  i = strtol(str, NULL, 10);
    /* char output */
    if (i < 0 || i > 127)
        std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(i);
        if (isprint(c))
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
    }

    // float f = strtof(str, &endptr);
    // std::cout << f << std::endl;
    // std::cout << endptr << std::endl;


    // double d = strtod(str, &endptr);
    // std::cout << d << std::endl;
    // std::cout << strlen(str) - 1 << std::endl;
    // if (endptr != &str[strlen(str)])
    //     std::cerr << "Error: Invalid\n"; 
}