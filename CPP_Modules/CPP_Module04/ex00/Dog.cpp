#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called\n";
    this->type = "Dog";
}

Dog::Dog(const Dog & ref)
{
    *this = ref;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    this->type = "Dog";
}

Dog & Dog::operator=(Dog const & rhs)
{
    this->type = rhs.getType();
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "* Wouaf Wouaf *\n";
}