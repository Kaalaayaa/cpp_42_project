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