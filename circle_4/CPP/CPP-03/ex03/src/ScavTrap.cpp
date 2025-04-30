/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:53:12 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/29 13:05:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << CYAN_LIGHT << "ScavTrap from ClapTrap " << GRAY <<  this->_name << CYAN_LIGHT << " created with default constructor." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << CYAN << "ScavTrap " << GRAY <<  this->_name << CYAN << " created with parameterized constructor." << RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << PURPLE << "ScavTrap " << GRAY <<  this->_name << PURPLE << " destroyed." << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << CYAN_DARK << "ScavTrap " << this->_name << CYAN_DARK << " created with copy constructor." << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << YELLOW << "ScavTrap  "<< GRAY << this->_name << YELLOW << " assigned with copy assignment operator." << RESET << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << GRAY << this->_name << RED << " attacks " << GRAY
			<< target << RESET << ", causing " << RED_LIGHT << this->_attackDamage
			<< " points of damage!" << RESET << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << GRAY << this->_name << RESET << " can't" << RED
		<< " attack" << RESET << ", he is out of ";
	if (this->_hitPoints == 0)
		std::cout << RED_LIGHT << "hit points!" << RESET;
	else
		std::cout << BROWN << "energy points!" << RESET;
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
		std::cout << "Cannot switch to gate-keeper mode because: ScavTrap " << GRAY << this->_name << RESET
			<< " is " << RED_LIGHT << "out of hit points!" << RESET << std::endl;
	else
		std::cout << "ScavTrap " << GRAY << this->_name << RESET << " is now in gate-keeper mode." << std::endl;
}
