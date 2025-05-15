#include "Zombie.hpp"

/* create a new zombie on the stack and announce itself */
void    randomChump(std::string name)
{
    Zombie  randomChump(name);
    randomChump.announce();
}