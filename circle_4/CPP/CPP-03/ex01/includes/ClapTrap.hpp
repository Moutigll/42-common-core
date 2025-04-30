/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:47:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 12:28:38 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

// Constructors
#define CYAN_LIGHT "\033[38;5;159m" // Default constructor
#define CYAN "\033[38;5;45m"        // Parameterized constructor
#define CYAN_DARK "\033[38;5;25m"   // Copy constructor

#define PURPLE "\033[38;5;93m" // Destructor
#define YELLOW "\033[38;5;226m" // Assignment operator

#define GRAY "\033[38;5;240m" // Name
#define RED "\033[38;5;196m" // Attack
#define RED_LIGHT "\033[38;5;203m" // Take damage
#define GREEN "\033[38;5;82m" // Be repaired
#define BROWN "\033[38;5;130m" // Out of energy

#define RESET "\033[0m" // Reset color

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
};

#endif