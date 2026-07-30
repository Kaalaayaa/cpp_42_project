#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hp(10), ep(10), ad(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0)
{
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    name = other.name;
    hp = other.hp;
    ep = other.ep;
    ad = other.ad;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hp <= 0 || ep <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because it has no hit points or energy points left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
    ep--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp <= 0 || ep <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair because it has no hit points or energy points left" << std::endl;
        return;
    }
    hp = hp + amount;
    ep--;
    std::cout << "ClapTrap " << name << " repairs itself, regaining " << amount << " hit points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp <= 0)
    {
        std::cout << "ClapTrap " << name << " is already at 0 hit points" << std::endl;
        return;
    }
    if (hp  <= static_cast<int>(amount))
        hp = 0;
    else
        hp = hp - amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage" << std::endl;
}
