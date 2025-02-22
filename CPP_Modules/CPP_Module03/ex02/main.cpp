#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
    ScavTrap first("CLP4P-TP");
    ScavTrap copy1(first);

    //base
    first.guardGate();
    first.attack("Bandit");
    first.takeDamage(99);
    first.beRepaired(5);

    //spend all energy point
    for(int i = 0; i < 50; i++)
        first.attack("Bandit");
    first.guardGate();
    first.beRepaired(8);
    //die
    first.takeDamage(7);
    first.guardGate();
    first.attack("Bandit");
    first.beRepaired(8);

    FragTrap second("FRAP4P-TP");
    FragTrap copy2(second);
    second.highFivesGuys();
    second.attack("Bandit");
    second.takeDamage(99);
    second.beRepaired(5);
    
    //spend all energy point
        for(int i = 0; i < 100; i++)
        second.attack("Bandit");
    second.highFivesGuys();
    second.beRepaired(8);
    
    //die
    second.takeDamage(7);
    second.highFivesGuys();
    second.attack("Bandit");
    second.beRepaired(8);
}