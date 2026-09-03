#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal name constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
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