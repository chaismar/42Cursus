
#include "Array.hpp"

template<class T>
Array<T>::Array()
{
    data = new T[0];
    len = 0;
}

template<class T> 
Array<T>::Array(size_t i)
{
    data = new T[i];
    len = i;
}

template<class T>
Array<T>::Array(const Array<T> &src) : len(src.len) {
    data = new T[len];
    for (size_t i = 0; i < len; ++i) {
        data[i] = src.data[i];
    }
}

template<class T> 
Array<T>& Array<T>::operator=(const Array<T> &src) {
    if (this != &src) {
        delete[] data;
        len = src.len;
        data = new T[len];
        for (size_t i = 0; i < len; ++i) {
            data[i] = src.data[i];
        }
    }
    return *this;
}

template<class T>
Array<T>::~Array()
{
    delete[] data;
}

template<class T>
int Array<T>::size(void)
{
    return this->len;
}

template<class T>
T &Array<T>::operator[](size_t index)
{
    if (index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<class T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}