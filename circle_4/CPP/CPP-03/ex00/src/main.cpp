/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/23 21:58:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap claptrap("CLTP");
	ClapTrap copy(claptrap);

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	copy.attack("target2");
	copy.takeDamage(2);
	copy.beRepaired(1);

	claptrap.beRepaired(0);
	claptrap.beRepaired(10);
	claptrap.beRepaired(24);
	claptrap.beRepaired(0);
	claptrap.beRepaired(0);
	claptrap.beRepaired(0);
	claptrap.beRepaired(0);
	claptrap.beRepaired(0);
	claptrap.beRepaired(0);

	return 0;
}