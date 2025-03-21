/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:24:24 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/20 16:38:27 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int		main(void)
{
	Zombie	*zombie = newZombie("Zombie1");

	zombie->announce();
	randomChump("Zombie2");
	delete zombie;
	return (0);
}