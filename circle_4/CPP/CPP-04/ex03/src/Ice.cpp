/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:56:48 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 15:40:11 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const &other) : AMateria(other) {}

Ice::~Ice(void) {}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RST << std::endl;
}