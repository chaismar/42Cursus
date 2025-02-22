#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal{
    public :
        Cat();
        Cat(const Cat &ref);

        virtual ~Cat();

        Cat & operator=(Cat const &rhs);

        virtual void makeSound(void) const;
    private :
        Brain *brain;
};

#endif