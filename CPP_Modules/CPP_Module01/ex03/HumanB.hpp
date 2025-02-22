#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();

        std::string name;
        void attack(void);
        
        void setWeapon(Weapon &new_weapon);

        Weapon *w;
};