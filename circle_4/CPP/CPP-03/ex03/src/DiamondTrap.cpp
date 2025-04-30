/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:21:40 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 12:10:43 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << CYAN_LIGHT << "DiamondTrap default constructor called" << RESET << std::endl;
	this->_name = "DiamondTrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
	std::cout << CYAN << "DiamondTrap parameterized constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy)
{
	std::cout << CYAN_DARK << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << PURPLE << "DiamondTrap destructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << YELLOW << "DiamondTrap assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
	std::cout << "DiamondTrap " << GRAY << this->_name << RESET << " attacks with ScavTrap's attack! -> ";
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << GRAY << this->_name << RESET << " from ClapTrap name: " << GRAY << ClapTrap::_name << RESET << std::endl;
}