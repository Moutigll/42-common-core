/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:03:25 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 16:14:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << DC << "A new MateriaSource has appeared !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cout << CC << "A MateriaSource has been copied !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << D << "A MateriaSource has been destroyed !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << A << "A MateriaSource has been duplicated !" << RST << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			std::cout << MAGENTA << "MateriaSource: Learned a new materia of type " << m->getType() << RST << std::endl;
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout <<  RED << "MateriaSource: No space left to learn new materia" << RST << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	std::cout << RED << "MateriaSource: No materia of type " << type << " found" << RST << std::endl;
	return (NULL);
}