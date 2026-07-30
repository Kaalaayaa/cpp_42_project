/*
Exercise 00 - ClapTrap reminder

What this exercise is about:
- Create one class called ClapTrap.
- Give it a name, hit points, energy points, and attack damage.
- Add attack, takeDamage, and beRepaired.
- Show messages for constructor, destructor, and actions.

What I learned:
- How to make a class with private data and public functions.
- How constructors set the first values of an object.
- How a destructor runs when the object is destroyed.
- How to change an object’s state with member functions.
- How to check if the object can still act.

Important things to remember:
- attack and beRepaired cost 1 energy point.
- If hit points or energy points are 0, the ClapTrap cannot act.
- attack uses attack damage, not hit points.
- takeDamage must not let hit points go below 0.
- Keep the output messages clear because the evaluator checks them.
*/

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap a("Alpha");
    ClapTrap b( a );
    ClapTrap c("Charlie");
    c = b;
    a.attack("Bandit");
    b.beRepaired(4);
    a.takeDamage(3);
    a.attack("Bandit");
    return 0;
}