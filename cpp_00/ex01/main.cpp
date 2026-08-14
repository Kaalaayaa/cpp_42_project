#include "Phonebook.hpp"

#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (std::getline(std::cin, command))
    {
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
    }
    return 0;
}