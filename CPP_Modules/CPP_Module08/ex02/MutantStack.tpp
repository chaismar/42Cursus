#include "MutantStack.hpp"

template<class T>
MutantStack<T>::MutantStack()
{}
template<class T>
MutantStack<T>::~MutantStack()
{}

template<class T>
MutantStack<T>::MutantStack(MutantStack &src)
{
	*this = src;
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
	return (this->c.cbegin());
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	return (this->c.cend());
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template<class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return (this->c.crbegin());
}

template<class T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return (this->c.crend());
}