#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Animal constructor called\n";
    this->type = "default";
}

AAnimal::AAnimal(const AAnimal & ref)
{
    *this = ref;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called\n";
    this->type = "default";
}

void AAnimal::makeSound(void) const
{
    std::cout << "* Animal noises *\n";
}

std::string AAnimal::getType() const
{
    return (this->type);
}

void AAnimal::setType(std::string type)
{
    this->type = type;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
    std::cout<<"operator assignement called\n";
    this->type = rhs.getType();
    return *this;
}