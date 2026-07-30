/*
Exercise 02 - FragTrap reminder

What this exercise is about:
- Create FragTrap as a child of ClapTrap.
- Use inheritance instead of copying the whole class.
- Change FragTrap stats to hit points 100, energy points 100, attack damage 30.
- Give FragTrap its own attack message and highFivesGuys function.

What I learned:
- How inheritance works between a parent class and a child class.
- How the child can reuse the parent’s functions.
- Why some ClapTrap members must be protected so the child can use them.
- How constructor and destructor order works in inheritance.

Important things to remember:
- FragTrap is built on top of ClapTrap.
- The ClapTrap part is created first, then the FragTrap part.
- The FragTrap constructor sets the new stats after calling the ClapTrap constructor.
- FragTrap keeps inherited functions like takeDamage and beRepaired.
- highFivesGuys is the special FragTrap ability.
*/

#include "FragTrap.hpp"

int main(void)
{
    FragTrap frag("Fraggy");
    frag.attack("target");
    frag.highFivesGuys();
    frag.takeDamage(10);
    frag.beRepaired(5);
    return 0;
}