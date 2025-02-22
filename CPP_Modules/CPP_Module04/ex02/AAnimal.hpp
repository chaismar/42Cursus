#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal{
    public :
        AAnimal();
        AAnimal(const AAnimal & ref);

        virtual ~AAnimal() = 0;

        AAnimal & operator=(AAnimal const & rhs);
        
        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
        void setType(std::string type);

    protected :
        std::string type;
};

#endif