/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:13:10 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/03 18:31:58 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde(int N, str name)
{
	if (N <= 0)
	{
		std::cerr << "Error: N must be greater than 0." << std::endl;
		return (NULL);
	}
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << name << i;
		horde[i].setName(oss.str());
	}
	return (horde);
}
