/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:25:09 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/29 13:30:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 20;
	std::cout << CYAN_LIGHT << "FragTrap from ClapTrap " << GRAY <<  this->_name << CYAN_LIGHT << " created with default constructor." << RESET << std::endl;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 20;
	std::cout << CYAN << "FragTrap " << GRAY <<  this->_name << CYAN << " created with parameterized constructor." << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << PURPLE << "FragTrap " << GRAY <<  this->_name << PURPLE << " destroyed." << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << CYAN_DARK << "FragTrap " << this->_name << CYAN_DARK << " created with copy constructor." << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << YELLOW << "FragTrap  "<< GRAY << this->_name << YELLOW << " assigned with copy assignment operator." << RESET << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << GRAY << this->_name << RED << " attacks " << GRAY
			<< target << RESET << ", causing " << RED_LIGHT << this->_attackDamage
			<< " points of damage!" << RESET << std::endl;
		return ;
	}
	std::cout << "FragTrap " << GRAY << this->_name << RESET << " can't" << RED
		<< " attack" << RESET << ", he is out of ";
	if (this->_hitPoints == 0)
		std::cout << RED_LIGHT << "hit points!" << RESET;
	else
		std::cout << BROWN << "energy points!" << RESET;
	std::cout << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << GRAY << this->_name << RESET << " can't high five, he is"
			<< RED << " out of hit points!" << RESET << std::endl;
		return ;
	}
	std::cout << "FragTrap " << GRAY << this->_name << RESET << " is requesting a high five!" << std::endl;
}