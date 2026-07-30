#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other); // copy constructor = called when creating a new object form another object
	FragTrap& operator=(const FragTrap& other); // copy assigment operator = called when object already exist 
	~FragTrap(); // destructor = called automitacally when object is destroyed
	void attack(const std::string& target);
	void highFivesGuys(void);
};


#endif