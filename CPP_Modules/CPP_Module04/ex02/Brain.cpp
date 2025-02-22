#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
	std::cout << "Brain copy constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

std::string *Brain::getIdeas(void)
{
	return (this->ideas);
}

void Brain::setIdeas(std::string val[100])
{
	for (int i = 0; i < (int)val->length(); i++)
		this->ideas[i] = val[i];
}

Brain & Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}