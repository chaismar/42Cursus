#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class Array
{
    public :
        Array();
        Array(size_t);
        Array(const Array &src);
        ~Array();
        Array &operator=(const Array &src);
        int size(void);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
    private:
        T* data;
        size_t len;
};

#include "Array.tpp"

#endif