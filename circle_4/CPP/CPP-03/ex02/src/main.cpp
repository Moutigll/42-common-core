/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/24 01:30:56 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int	main(void)
{
	std::cout << "----------Creating claptrap number 1----------" << std::endl;
	ClapTrap claptrap("ClapTrap number 1");
	std::cout << "----------Creating FragTrap number 1----------" << std::endl;
	FragTrap fragtrap1("FragTrap number 1");
	std::cout << "----------Creating FragTrap number 2----------" << std::endl;
	FragTrap fragtrap2(fragtrap1);
	std::cout << "----------Creating FragTrap number 3----------" << std::endl;
	FragTrap fragtrap3;
	std::cout << "----------Assigning FragTrap number 1 to FragTrap number 3----------" << std::endl;
	fragtrap3 = fragtrap1;
	claptrap.attack("FragTrap number 1");
	fragtrap1.attack("ClapTrap number 1");
	claptrap.takeDamage(5);
	fragtrap1.takeDamage(5);
	fragtrap3.beRepaired(5);
	fragtrap3.highFivesGuys();
	fragtrap2.attack("ClapTrap number 1");
	fragtrap2.takeDamage(5);
	fragtrap1.takeDamage(5);

	return (0);
}
