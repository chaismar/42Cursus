#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* h = new Zombie[N];
    std::stringstream stream;
    std::string num;
    
    for (int i = 0; i < N; i++)
    {
        stream << i+1;
        stream >> num;
        h[i].set_name(name + "_" + num);
    }
    return (&(h[0]));
}