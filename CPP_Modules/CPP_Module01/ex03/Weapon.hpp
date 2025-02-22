#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class  Weapon
{
    public:
        Weapon();
        Weapon(std::string);
        ~ Weapon();
    
        std::string	const & get_type() const;
        void setType(std::string);
    
    private:
        std::string type;
};

#endif