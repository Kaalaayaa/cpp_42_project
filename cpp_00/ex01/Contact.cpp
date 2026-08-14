#include "Contact.hpp"

void Contact::setInfo(std::string fname, std::string lname, std::string nname,
	std::string phone, std::string secret)
{
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