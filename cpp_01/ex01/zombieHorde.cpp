#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    Zombie* zombie = new Zombie[N];
    while(i < N)
    {
        zombie[i].setName(name);
        i++;
    }
    return zombie;
}