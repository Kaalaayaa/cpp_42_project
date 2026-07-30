#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other); // copy constructor = called when creating a new object form another object
	ScavTrap& operator=(const ScavTrap& other); // copy assigment operator = called when object already exist 
	~ScavTrap(); // destructor = called automitacally when object is destroyed
	void attack(const std::string& target);
	void guardGate();
};


#endif