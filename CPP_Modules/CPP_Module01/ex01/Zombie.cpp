#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie()
{
    std::cout<< this->name << " as been created\n";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout<< this->name << " as been destroyed\n";
}

void Zombie::announce(void)
{
    std::cout<< this->name << ": BraiiiiiiinnnzzzZ...\n";
    return ;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
    return ;
}