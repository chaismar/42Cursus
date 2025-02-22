#include "Span.hpp"

Span::Span() : numbers(0)
{
    this->len = 0;
}

Span::Span(unsigned int size)
{
    this->len = size;
    this->numbers = std::vector<int>();
}

Span::Span(const Span &copy)
{
    this->len = copy.len;
    this->numbers.clear();
    this->numbers = copy.numbers;
}

Span::~Span(){}

Span &Span::operator=(Span &copy)
{
    this->len = copy.len;
    this->numbers.clear();
    this->numbers = copy.numbers;
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->numbers.size() < this->len)
        this->numbers.push_back(n);
    else
        throw VectorIsFull();
}

unsigned long Span::shortestSpan()
{
    std::vector<int> sorted;
    if(this->numbers.size() <= 1)
        throw (Span::ShortSpanException());
    sorted = this->numbers;
    std::sort(sorted.begin(), sorted.end());
    return (sorted[1]-1 - sorted[0]);
}

unsigned long Span::longestSpan()
{
    std::vector<int> sorted;
    if(this->numbers.size() <= 1)
        throw (Span::LongSpanException());
    sorted = this->numbers;
    std::sort(sorted.begin(), sorted.end());
    return (sorted[sorted.size() - 1] - sorted[0]);
}

const char* Span::VectorIsFull::what() const throw()
{
	return "Vector is FULL";
}

const char* Span::ShortSpanException::what() const throw()
{
    return "ShortSpanException";
}

const char* Span::LongSpanException::what() const throw()
{
    return "LongSpanException";
}

