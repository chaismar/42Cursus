#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called\n";
    this->type = "Cat";
    this->brain = new Brain;
}

Cat::Cat(const Cat &ref) : Animal(ref)
{
    this->type = ref.type;
    this->brain = new Brain;
}

Cat::~Cat()
{
    if (this->brain)
        delete(this->brain);
    std::cout << "Cat destructor called\n";
}


Cat & Cat::operator=(Cat const &rhs)
{
    this->type = rhs.getType();
    this->brain->setIdeas(rhs.brain->getIdeas()); 
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "* Miaooooouuuuu *\n";
}