#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

/*
 * Exercise 02 reminder: "Abstract class"
 *
 * PURPOSE:
 * An AAnimal by itself does not make sense, so AAnimal must be abstract. This
 * prevents code from creating an AAnimal object directly while still allowing
 * Dog and Cat objects to be used through AAnimal pointers.
 *
 * CLASS DESIGN:
 * - AAnimal::makeSound() is pure virtual (= 0), which makes AAnimal abstract.
 * - AAnimal still provides shared data, constructors, copying, getType(), and
 *   a virtual destructor for its derived classes.
 * - Dog and Cat each have a private Brain* member.
 * - Their constructors allocate the Brain with new Brain().
 * - Their destructors delete the Brain.
 * - Brain stores 100 std::string ideas.
 *
 * RULE OF THREE:
 * Because Dog and Cat own memory, they implement:
 * 1. A destructor to release the Brain.
 * 2. A copy constructor to allocate a new Brain containing copied ideas.
 * 3. A copy assignment operator to copy ideas into independent storage.
 *
 * A shallow copy would make two animals point to the same Brain. Then
 * changing one animal's idea would change the other animal's idea too, and
 * both destructors would try to delete the same pointer. That is why copies
 * must be deep copies.
 *
 * TESTS TO REMEMBER:
 * - AAnimal animal; would fail to compile because AAnimal is abstract. Do not
 *   add that line to a compiling test; this rule is checked by the compiler.
 * - new Dog() and new Cat() are deleted through AAnimal*.
 * - An array contains five Dogs and five Cats and deletes all ten safely.
 * - makeSound() demonstrates runtime polymorphism.
 * - Dog a; Dog b(a); checks the copy constructor.
 * - Cat d; d = c; checks the copy assignment operator.
 * - After changing a copied Brain, the original Brain must stay unchanged.
 * - Constructor and destructor messages help verify the order of cleanup.
 * - Run a leak checker after compiling. Every new must have one matching
 *   delete, and no object may be deleted twice.
 *
 * getBrain() is only an accessor used by these tests. It allows main() to
 * change an idea without making the Brain* member itself public. The const
 * overload allows read-only access when the Dog or Cat is const.
 */
int main(void)
{
    const AAnimal *j = new Dog();
    const AAnimal *cat = new Cat();

    delete j;
    delete cat;

    AAnimal *animals[10];
    for (int i = 0; i < 5; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; i++)
    {
        animals[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }

    Dog a;
    a.getBrain()->ideas[0] = "hello";
    Dog b(a);
    b.getBrain()->ideas[0] = "bone";
    std::cout << "Dog copy: " << a.getBrain()->ideas[0] << " / "
              << b.getBrain()->ideas[0] << std::endl;

    Cat c;
    c.getBrain()->ideas[0] = "fish";
    Cat d;
    d = c;
    d.getBrain()->ideas[0] = "milk";
    std::cout << "Cat assignment: " << c.getBrain()->ideas[0] << " / "
              << d.getBrain()->ideas[0] << std::endl;
    return 0;
}
