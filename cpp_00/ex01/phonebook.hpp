#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact
{
public:
	void setInfo(std::string fname, std::string lname, std::string nname,
		std::string phone, std::string secret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
};

class PhoneBook
{
public:
	PhoneBook();
	void addContact();
	void searchContact();

private:
	Contact contacts[8];
	int currentIndex;
};

#endif
