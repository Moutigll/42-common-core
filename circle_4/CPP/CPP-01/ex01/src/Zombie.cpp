/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:28:31 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 16:48:39 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(str name) : _name(name)
{
	return ;
}

Zombie::Zombie(void) : _name("Zombie")
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is dead." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(str name)
{
	_name = name;
}
