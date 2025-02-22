#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->setName("FRAG-TP");
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDamage(30);
    this->setMaxHitPoint(100);
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name)
{
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDamage(30);
    this->setMaxHitPoint(100);
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap &ref)
{
    std::cout << "FragTrap copy constructor called\n";
    *this = ref;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap Copy assignement operator called\n";
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

void FragTrap::highFivesGuys()
{
    if (this->getHitPoint() <= 0)
    {
        std::cout << this->getName() << "is dead he can't bounce anymore. Rest in peace little robot\n";
    }
    std::cout << "Bounce Bounce Bounce \"Check\" Bounce Bounce Bounce\n";
}