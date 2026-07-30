#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    hp = 100;
    ep = 100;
    ad = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hp = 100;
    ep = 100;
    ad = 30;
    std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (hp <= 0 || ep <= 0)
    {
        std::cout << "FragTrap " << name << " cannot attack because it has no hit points or energy points left" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
    ep--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high-five!" << std::endl;
}
