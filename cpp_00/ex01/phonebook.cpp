#include "Phonebook.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>

static bool isEmpty(const std::string value)
{
    return value.find_first_not_of(" \t") == std::string::npos;
}

static std::string readField(const std::string prompt)
{
    std::string value;

    while (isEmpty(value))
    {
        std::cout << prompt;
        if (!std::getline(std::cin, value))
            return std::string();
    }
    return value;
}

static std::string formatColumn(const std::string value)
{
    if (value.length() > 10)
        return value.substr(0, 9) + ".";
    return value;
}

PhoneBook::PhoneBook()
{
    currentIndex = 0;
}

void PhoneBook::addContact()
{
    std::string fName = readField("First name: ");
    if (fName.empty())
         return;
    std::string lName = readField("Last name: ");
    if (lName.empty())
        return;
    std::string nName = readField("Nickname: ");
    if (nName.empty())
        return;
    std::string phone = readField("Phone Number: ");
    if (phone.empty())
        return;
    std::string secret = readField("Darkest Secret: ");
    if (secret.empty())
        return;
    contacts[currentIndex % 8].setInfo(fName, lName, nName, phone, secret);
    currentIndex++;
}

void PhoneBook::searchContact()
{
    int total = currentIndex < 8 ? currentIndex : 8;
    if (total == 0)
        return;
    for (int i = 0; i < total; ++i)
    {
        std::cout << std::right << std::setw(10) << i << "|"
                  << std::right << std::setw(10) << formatColumn(contacts[i].getFirstName()) << "|"
                  << std::right << std::setw(10) << formatColumn(contacts[i].getLastName()) << "|"
                  << std::right << std::setw(10) << formatColumn(contacts[i].getNickName()) << "\n";
    }
    std::string input;
    int index;
    while (1)
    {
        std::cout << "Index: ";
        if (!std::getline(std::cin, input))
            return;
        std::stringstream ss(input);
        if (ss >> index && ss.eof() && index >= 0 && index < total)
            break;
        std::cout << "Invalid index\n";
    }
    std::cout << contacts[index].getFirstName() << "\n";
    std::cout << contacts[index].getLastName() << "\n";
    std::cout << contacts[index].getNickName() << "\n";
    std::cout << contacts[index].getPhoneNumber() << "\n";
    std::cout << contacts[index].getDarkestSecret() << "\n";
}