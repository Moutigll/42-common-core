/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:15:57 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 17:16:16 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(str type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

str const	&Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(str type)
{
	_type = type;
}
