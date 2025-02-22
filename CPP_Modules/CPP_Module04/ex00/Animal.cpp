#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called\n";
    this->type = "default";
}

Animal::Animal(const Animal & ref)
{
    *this = ref;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
    this->type = "default";
}

void Animal::makeSound(void) const
{
    std::cout << "* Animal noises *\n";
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::setType(std::string type)
{
    this->type = type;
}

Animal & Animal::operator=(Animal const & rhs)
{
    std::cout<<"operator assignement called\n";
    this->type = rhs.getType();
    return *this;
}