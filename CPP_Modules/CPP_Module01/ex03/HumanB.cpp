#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	this->w = NULL;
}

HumanB::~HumanB(){

}

void HumanB::setWeapon(Weapon &new_weapon)
{
    this->w = &new_weapon;
    return ;
}

void HumanB::attack(void)
{
    if (this->w)
        std::cout<< this->name << " attacks with " << (*(this->w)).get_type() << std::endl;
    else
        std::cout<< this->name << " attacks with his fists" << std::endl;
    return ;
}