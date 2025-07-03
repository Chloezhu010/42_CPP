#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cerr << "Error: Need at least two number to sort\n";
        return (1);
    }
    
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        int nb;

        if (iss >> nb)
        {
            if (nb > 0 )
                std::cout << nb << "\n";
        }
        else
            std::cerr << "Error: invalid input\n";
    }

    return (0);
}