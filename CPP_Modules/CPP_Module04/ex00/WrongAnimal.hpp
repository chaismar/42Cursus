#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &ref);

        virtual ~WrongAnimal();

        WrongAnimal & operator=(WrongAnimal const & rhs);
        
        virtual void makeSound(void) const;
        std::string getType(void) const;
		void setType(std::string type);

    protected :
        std::string type;
};

#endif