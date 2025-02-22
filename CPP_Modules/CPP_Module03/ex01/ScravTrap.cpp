#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called";
    this->setName("SCAV-TP");
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    this->setMaxHitPoint(100);
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called\n";
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDamage(20);
    this->setMaxHitPoint(100);
}

ScavTrap::ScavTrap(const ScavTrap &ref)
{
    std::cout << "ScavTrap Copy constructor called\n";
    *this = ref;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
    std::cout << "ScavTrap Copy assignement operator called\n";
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

void ScavTrap::guardGate()
{
    if(this->getHitPoint() <= 0)
    {
        std::cout << this->getName() << " is dead he can't guard the gate anymore. Rest in peace little robot\n";
        return ;
    }
    std::cout << "ScavTrap is now in gate keeper mode\n";
    return ;
}