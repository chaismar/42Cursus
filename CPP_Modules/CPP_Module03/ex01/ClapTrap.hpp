#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap{
    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &ref);
        ~ClapTrap();

        ClapTrap & operator=(ClapTrap const & rhs);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName();
        int getHitPoint();
        int getEnergyPoint();
        int getAttackDamage();
        int getMaxHitPoint();

        void setName(std::string val);
        void setHitPoint(int val);
        void setEnergyPoint(int val);
        void setAttackDamage(int val);
        void setMaxHitPoint(int val);

    private :
        std::string name;
        int     hit_point;
        int     energy_point;
        int     attack_damage;
        int     max_hit_point;

};

#endif
