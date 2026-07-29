#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string name;
	int hp;
	int ep;
	int ad;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other); // copy constructor = called when creating a new object form another object
	ClapTrap& operator=(const ClapTrap& other); // copy assigment operator = called when object already exist 
	~ClapTrap(); // destructor = called automitacally when object is destroyed
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif