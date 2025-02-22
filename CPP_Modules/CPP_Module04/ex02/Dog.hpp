#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal{
    public :
        Dog();
        Dog(const Dog &ref);

        virtual ~Dog();

        Dog & operator=(Dog const &rhs);

        virtual void makeSound(void) const;
    private :
        Brain *brain;
};

#endif