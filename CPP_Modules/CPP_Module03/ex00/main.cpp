#include "ClapTrap.hpp"

int main ()
{
    ClapTrap first("CLP4P-TP");
    ClapTrap copy(first);

    first.attack("Bandit");
    first.takeDamage(8);
    first.beRepaired(2);
    first.beRepaired(5);
    first.takeDamage(4);
    first.attack("Bandit");
    first.beRepaired(2);
    first.takeDamage(2);

    ClapTrap second("CLP4P-TP-2");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.attack("Bandit");
    second.beRepaired(2);
    return (0);
}