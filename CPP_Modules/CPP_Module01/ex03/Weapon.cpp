#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{

}

std::string	const &Weapon::get_type() const
{
    return this->type;
}

void Weapon::setType(std::string s)
{
    this->type = s;
    return ;
}