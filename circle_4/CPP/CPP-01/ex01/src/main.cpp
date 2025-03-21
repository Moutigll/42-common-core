/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:24:05 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 17:05:37 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie*	horde = zombieHorde(42, "Jeanmichel");

	for (int i = 0; i < 42; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
