#include "Zombie.hpp"

Zombie::Zombie() : name("default") {}
Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}