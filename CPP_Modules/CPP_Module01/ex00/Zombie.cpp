#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie()
{
    this->name = "default Zombie";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout<< this->name << " as been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout<< this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
    return ;
}