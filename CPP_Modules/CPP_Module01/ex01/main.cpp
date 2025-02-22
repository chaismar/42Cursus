#include "Zombie.hpp"
#include "zombieHorde.cpp"
#include <cstdlib>

int main()
{
    Zombie *l = zombieHorde(5, "test");

    for(int i = 0; i < 5; i++)
        l[i].announce();
    delete [] (l);
}