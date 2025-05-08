/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:50:30 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 15:40:44 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RST << std::endl;
}
