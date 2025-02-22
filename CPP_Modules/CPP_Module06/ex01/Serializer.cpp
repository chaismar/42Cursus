#include "Serializer.hpp"
#include <stdint.h>
#include <stddef.h>

Serializer::Serializer(){
    std::cout << "Serializer constructor called" << std::endl;
}

Serializer::~Serializer(){
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
    if (&cpy != this)
        std::cout << "Serializer copy constructor called" << std::endl;
    else
        std::cout << "Error with data for copy constructor" << std::endl;
}

Serializer& Serializer:: operator=(const Serializer &cpy)
{
    if (this != &cpy)
        return (*this);
    return (*this);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}