#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
    ScavTrap first("CLP4P-TP");
    ScavTrap copy(first);

    //base
    first.guardGate();
    first.attack("Bandit");
    first.takeDamage(50);
    first.beRepaired(20);
    // first.takeDamage(70);

    //spend all energy point
    for(int i = 0; i < 50; i++)
        first.attack("Bandit");
    first.guardGate();
    first.beRepaired(8);
    //die
    first.takeDamage(70);
    first.guardGate();
    first.attack("Bandit");
    first.beRepaired(8);
}