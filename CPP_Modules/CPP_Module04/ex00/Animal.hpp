#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    public :
        Animal();
        Animal(const Animal & ref);

        virtual ~Animal();

        Animal & operator=(Animal const & rhs);
        
        virtual void makeSound(void) const;
        std::string getType(void) const;
        void setType(std::string type);

    protected :
        std::string type;
};

#endif