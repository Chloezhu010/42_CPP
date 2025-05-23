#include <iostream>
#include <cmath>

/* test roundf() */
int main()
{
    float f = 3.8f;

    int raw = f * 256;
    std::cout << "raw value (without roundf): " << raw << std::endl;

    int raw_roundf = roundf(f * 256);
    std::cout << "raw value (roundf): " << raw_roundf << std::endl;
}