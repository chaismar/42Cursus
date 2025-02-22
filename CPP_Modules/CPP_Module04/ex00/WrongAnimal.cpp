#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called\n";
	this->type = "wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal copy constructor called\n";
	*this = ref;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "* Wrong Animal noises *\n";
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->type = rhs.getType();
	return (*this);
}