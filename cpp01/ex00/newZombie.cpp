#include "Zombie.hpp"

/* create a new zombie on the heap with new */
Zombie  *newZombie(std::string name)
{
    Zombie  *newZombie;

    newZombie = new Zombie(name);
    return (newZombie);
}