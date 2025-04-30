/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:50:08 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/29 13:01:07 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CYAN_LIGHT << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CYAN << "Parameterized constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << CYAN_DARK << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << PURPLE << "Destructor called" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << YELLOW << "Assignment operator called" << RESET << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << GRAY << _name << RED << " attacks " << GRAY
			<< target << RESET << ", causing " << RED_LIGHT << _attackDamage
			<< " points of damage!" << RESET << std::endl;
		return;
	}
	std::cout << "ClapTrap " << GRAY << _name << RESET << " can't" << RED
		<< " attack" << RESET << ", he is out of ";
	if (_hitPoints == 0)
		std::cout << RED_LIGHT << "hit points!" << RESET;
	if (_energyPoints == 0)
		std::cout << BROWN << "energy points!" << RESET;
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else if (this->_hitPoints > 0)
		this->_hitPoints = 0;
	else
	{
		std::cout << "ClapTrap " GRAY << this->_name << RESET
			<< " is already " << RED << "dead!" << RESET << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << GRAY << this->_name << RESET
		<< " takes " RED_LIGHT << amount << " points of damage!" << RESET
		<< " Hit points left: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0) {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << GRAY << _name << GREEN << " repairs itself for "
			<< amount << " hit points!" << RESET
			<< " Hit points now: " << _hitPoints << std::endl;
		return;
	}
	std::cout << "ClapTrap " << GRAY << _name << RESET << " can't" << GREEN
		<< " be repaired" << RESET << ", he is";
	if (_hitPoints == 0)
		std::cout << " out of " << RED_LIGHT << "hit points!" << RESET;
	if (_energyPoints == 0)
		std::cout << " out of " << BROWN << " energy points!" << RESET;
	std::cout << std::endl;
}
