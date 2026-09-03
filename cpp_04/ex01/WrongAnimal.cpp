#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal name constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}
