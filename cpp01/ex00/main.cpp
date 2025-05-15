#include "Zombie.hpp"

int main()
{
    // stack allocation
    Zombie stackZombie("stackZombie");
    stackZombie.announce();

    // heap allocation
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;

    // random chump
    randomChump("randomChump");
    return (0);
}