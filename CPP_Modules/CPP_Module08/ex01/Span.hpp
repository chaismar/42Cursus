#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

class Span
{
    private :
        unsigned int len;
        std::vector<int> numbers;

    public :  
        Span();
        Span(unsigned int size);
        Span(const Span &copy);
        ~Span();
        Span &operator=(Span &copy);
        void addNumber(int n);
        template < class Iterator >
        void addNumber(Iterator begin, Iterator end);
        unsigned long shortestSpan();
        unsigned long longestSpan();
        class ShortSpanException: public std::exception {
            public :
            virtual const char* what() const throw();
        };
        class LongSpanException: public std::exception {
            public :
            virtual const char* what() const throw();
        };
        class VectorIsFull : public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
};

template <class Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

#endif