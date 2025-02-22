#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), w(w)
{
}

HumanA::~HumanA()
{

}

void HumanA::attack(void)
{
    std::cout<< this->name << " attacks with " << this->w.get_type()<< std::endl;
    return ;
}