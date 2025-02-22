#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called\n";
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::Dog(const Dog & ref) : AAnimal(ref)
{
    this->type = ref.type;
    this->brain = new Brain;
}

Dog::~Dog()
{
    delete(this->brain);
    std::cout << "Dog destructor called\n";
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