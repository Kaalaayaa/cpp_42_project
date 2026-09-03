#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\nWrongAnimal/WrongCat tests" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n Copy + assigment" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    dog2.makeSound();

    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    cat2.makeSound();

    std::cout << "\n=== Stack allocation tests ===" << std::endl;
    Animal animal;
    Dog dog;
    Cat cat;

    animal.makeSound();
    dog.makeSound();
    cat.makeSound();
    return 0;
}
