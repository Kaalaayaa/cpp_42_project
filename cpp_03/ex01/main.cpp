/*
Exercise 01 - ScavTrap reminder

What this exercise is about:
- Create ScavTrap as a child of ClapTrap.
- Use inheritance instead of copying the whole class.
- Change ScavTrap stats to hit points 100, energy points 50, attack damage 20.
- Give ScavTrap its own attack message and guardGate function.

What I learned:
- How inheritance works between a parent class and a child class.
- How the child can reuse the parent’s functions.
- Why some ClapTrap members must be protected so the child can use them.
- How constructor and destructor order works in inheritance.

Important things to remember:
- ScavTrap is built on top of ClapTrap.
- The ClapTrap part is created first, then the ScavTrap part.
- The ScavTrap constructor sets the new stats after calling the ClapTrap constructor.
- Only the attack function needs a new ScavTrap version here.
- guardGate is the special ScavTrap ability.
*/

#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clap("Clap");
    clap.attack("target");
    clap.beRepaired(2);

    std::cout << std::endl;

    ScavTrap scav("Scav");
    scav.attack("target");
    scav.guardGate();
    scav.takeDamage(20);
    scav.beRepaired(5);
    return 0;
}