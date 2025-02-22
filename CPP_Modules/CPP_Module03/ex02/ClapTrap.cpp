#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout<< "Constructor called\n";
    this->name = "CLP4P-TP";
    this->attack_damage = 0;
    this->energy_point = 10;
    this->hit_point = 10;
    this->max_hit_point = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Constructor called\n";
    this->name = name;
    this->attack_damage = 0;
    this->energy_point = 10;
    this->hit_point = 10;
    this->max_hit_point = 10;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
    *this = ref;
    std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "ClapTrap Copy assignement operator called\n";
    this->name = rhs.name;
    this->hit_point = rhs.hit_point;
    this->energy_point = rhs.energy_point;
    attack_damage = rhs.attack_damage;
    this->max_hit_point = 10;
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hit_point <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead. Rest in peace little robot\n";
        return ;
    }
    if (this->energy_point <= 0)
    {
        std::cout << "ClapTrap " << this->name << " doesn't have enough energy point\n";
        return ;
    }
    this->energy_point--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " point of damage!\n";
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((int) amount <= 0)
    {
        std::cout << "Please input a positive value\n";
        return ;
    }
    if (this->hit_point <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead. Rest in peace little robot\n";
        return ;
    }
    if (amount > (unsigned int)this->max_hit_point)
        amount = this->max_hit_point;
    if (this->hit_point - (int)amount <= 0)
    {
        this->hit_point -= amount;
        std::cout << "ClapTrap " << this->name << " is dead after taking " << amount << " damages\n";
        return ;
    }
    this->hit_point -= amount;
    std::cout << "ClapTrap " << this->name << " took " << amount << " damage, " << this->hit_point << " hit point left\n";
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((int) amount <= 0)
    {
        std::cout << (int) amount << "\n";
        std::cout << "Please input a positive value\n";
        return ;
    }
    if (this->hit_point <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead. Rest in peace little robot\n";
        return ;
    }
    if (amount > (unsigned int)this->max_hit_point)
        amount = this->max_hit_point;
    if (this->energy_point <= 0)
    {
        std::cout << "ClapTrap " << this->name << " doesn't have enough energy point\n";
        return ;
    }
    this->energy_point--;
    if(this->hit_point + (int)amount > this->max_hit_point)
    {
        this->hit_point = this->max_hit_point;
        std::cout << "ClapTrap " << this->name << " have been full healed\n";
        return ;
    }
    this->hit_point += (int)amount;
    std::cout << "ClapTrap " << this->name << " regained " << amount << " hit point, he now has "<< this->hit_point << "\n";
}

std::string ClapTrap::getName()
{
    return this->name;
}

int ClapTrap::getHitPoint()
{
    return this->hit_point;
}
int ClapTrap::getEnergyPoint()
{
    return this->energy_point;
}
int ClapTrap::getAttackDamage()
{
    return this->attack_damage;
}
int ClapTrap::getMaxHitPoint()
{
    return this->max_hit_point;
}

void ClapTrap::setName(std::string val)
{
    this->name = val;
}

void ClapTrap::setHitPoint(int val)
{
    this->hit_point = val;
}
void ClapTrap::setEnergyPoint(int val)
{
    this->energy_point = val;
}
void ClapTrap::setAttackDamage(int val)
{
    this->attack_damage = val;
}
void ClapTrap::setMaxHitPoint(int val)
{
    this->max_hit_point = val;
}


