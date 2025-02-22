#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called\n";
    this->type = "Cat";
}

Cat::Cat(const Cat &ref)
{
    *this = ref;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    this->type = "Cat";
}

Cat & Cat::operator=(Cat const &rhs)
{
    this->type = rhs.getType();
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "* Miaooooouuuuu *\n";
}