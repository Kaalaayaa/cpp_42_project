#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Name constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}