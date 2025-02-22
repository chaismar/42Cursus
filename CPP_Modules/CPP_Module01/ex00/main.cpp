#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"
#include <cstdlib>

int main()
{
    Zombie *z1 = newZombie("test1");
    Zombie z2("Michel");
    Zombie z3;

    /*z1*/
    z1->announce();

    /*z2*/
    z2.announce();
    z2.set_name("test2");
    z2.announce();

    /*z3*/
    
    randomChump("test3");
    delete(z1);
}