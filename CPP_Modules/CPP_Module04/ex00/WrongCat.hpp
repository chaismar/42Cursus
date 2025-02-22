#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public :
		WrongCat();
        WrongCat(const WrongCat &ref);

        virtual ~WrongCat();

        WrongCat & operator=(WrongCat const &rhs);
        
        virtual void makeSound(void) const;
};

#endif