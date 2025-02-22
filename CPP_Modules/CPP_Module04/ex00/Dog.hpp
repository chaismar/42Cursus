#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal{
    public :
        Dog();
        Dog(const Dog &ref);

        virtual ~Dog();

        Dog & operator=(Dog const &rhs);

        virtual void makeSound(void) const;
};

#endif