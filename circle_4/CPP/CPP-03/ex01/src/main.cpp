/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/24 00:45:38 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "----------Creating claptrap number 1----------" << std::endl;
	ClapTrap claptrap("ClapTrap number 1");
	std::cout << "----------Creating scavtrap number 1----------" << std::endl;
	ScavTrap scavtrap("ScavTrap number 1");
	std::cout << "----------Creating claptrap number 2----------" << std::endl;
	ScavTrap scavtrap2(scavtrap);
	std::cout << "----------Creating scavtrap number 3----------" << std::endl;
	ScavTrap scavtrap3;
	std::cout << "----------Assigning scavtrap number 1 to scavtrap number 3----------" << std::endl;
	scavtrap3 = scavtrap;
	claptrap.attack("ScavTrap number 1");
	scavtrap.attack("ClapTrap number 1");
	claptrap.takeDamage(5);
	scavtrap.takeDamage(5);
	scavtrap3.beRepaired(5);
	scavtrap3.guardGate();
	scavtrap2.attack("ClapTrap number 1");
	scavtrap2.takeDamage(5);
	scavtrap.takeDamage(5);
	return (0);
}

