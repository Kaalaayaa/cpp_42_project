#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {};

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " << (weapon ? weapon->getType() : "no weapon") << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}



