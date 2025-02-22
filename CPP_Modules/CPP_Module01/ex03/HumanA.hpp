#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public :

        HumanA(std::string name, Weapon &w);
        ~HumanA();

        std::string name;
        Weapon &w;

        void attack(void);
};