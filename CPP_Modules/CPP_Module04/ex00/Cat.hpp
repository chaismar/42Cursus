#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal{
    public :
        Cat();
        Cat(const Cat &ref);

        virtual ~Cat();

        Cat & operator=(Cat const &rhs);

        virtual void makeSound(void) const;
};

#endif