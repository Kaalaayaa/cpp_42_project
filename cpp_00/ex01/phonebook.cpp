#include "phonebook.hpp"

#include <iostream>
#include <iomanip>
#include <string>

void Contact::setInfo(std::string fname, std::string lname, std::string nname, std::string phone, std::string secret) {
    firstName = fname;
    lastName = lname;
    nickName = nname;
    phoneNumber = phone;
    darkestSecret = secret;
}  

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickName; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

PhoneBook::PhoneBook()
{
    currentIndex = 0;
}

void PhoneBook::addContact()
{
    std::string fName, lName, nName, phone, secret;
    std::cout << "First name: ";
    std::cin >> fName;
    std::cout << "Last name: ";
    std::cin >> lName;
    std::cout << "Nickname: ";
    std::cin >> nName;
    std::cout << "Phone Number: ";
    std::cin >> phone;
    std::cout << "Dark Secret: ";
    std::cin >> secret;
    contacts[currentIndex % 8].setInfo(fName, lName, nName, phone, secret);
    std::cout << "contact added\n";
    currentIndex++;
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContact()
{
    int i = 0;
    int total = currentIndex < 8 ? currentIndex : 8;
    while (i < total)
    {
        std::cout << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << truncate(contacts[i].getNickName()) << "\n";
        i++;
    }
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= total)
    {
        std::cout << "Invalid index\n";
        std::cin.clear();
        std::cin.ignore();
        return;
    }
    std::cout << contacts[index].getFirstName() << "\n";
    std::cout << contacts[index].getLastName() << "\n";
    std::cout << contacts[index].getNickName() << "\n";
    std::cout << contacts[index].getPhoneNumber() << "\n";
    std::cout << contacts[index].getDarkestSecret() << "\n";
}

int main()
{
    PhoneBook phonebook;
    std::string command;
    while(1)
    {
        std::cout << "Please type ADD, SEARCH or EXIT: ";
        std::cin >> command;
        if(command != "ADD" && command != "SEARCH" && command != "EXIT")
        {
            std::cout << "Wrong command\n";
            continue;
        }
        if(command == "ADD")
        {
            phonebook.addContact();
            continue;

        }
        else if(command == "SEARCH")
        {
            phonebook.searchContact();
            continue;
        }
        else if(command == "EXIT")
            break;
    }
    return 0;
}