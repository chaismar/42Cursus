#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &ref)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = ref;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong miaouuuuuuuu\n";
}

WrongCat & WrongCat::operator=(WrongCat const &rhs)
{
	this->type = rhs.getType();
	return *this;
}
