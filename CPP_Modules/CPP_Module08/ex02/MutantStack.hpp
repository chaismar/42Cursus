#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(MutantStack &src);
		~MutantStack();
		MutantStack &operator=(const MutantStack &src)
		{
			*this->c = src.c;
			return this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin() const;
		const_iterator cend() const;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;

};

#include "MutantStack.tpp"

#endif