/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:22:24 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 17:03:41 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(std::string name) : _name(name), _dropped(0), _numDropped(0)
{
	std::cout << YELLOW << this->_name << DC << " has entered the game !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = 0;
}

Character::Character(Character const &other) : _name(other._name), _dropped(0), _numDropped(other._numDropped)
{
	std::cout << YELLOW << other._name << CC << " has been copied !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
		else
			this->_materia[i] = 0;
	}
	if (_numDropped > 0)
	{
		this->_dropped = new AMateria*[_numDropped];
		for (int i = 0; i < _numDropped; i++)
		{
			this->_dropped[i] = other._dropped[i]->clone();
		}
	}
}

Character::~Character()
{
	std::cout << RED << this->_name << D << " has left the game !" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
	for (int i = 0; i < _numDropped; i++)
		if (_dropped[i])
		{
			std::cout << YELLOW << this->_name << CC
			          << " deleted dropped materia of type " << _dropped[i]->getType()
			          << RST << std::endl;
			delete _dropped[i];
		}
	delete[] _dropped;
}

Character &Character::operator=(Character const &other)
{
	std::cout << YELLOW << other._name << A << " has been duplicated !" << RST << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			if (this->_materia[i])
				delete this->_materia[i];
		for (int i = 0; i < _numDropped; i++)
			if (_dropped[i])
				delete _dropped[i];
		delete[] _dropped;

		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = 0;
		}
		_numDropped = other._numDropped;
		_dropped = 0;
		if (_numDropped > 0)
		{
			_dropped = new AMateria*[_numDropped];
			for (int i = 0; i < _numDropped; i++)
				_dropped[i] = other._dropped[i]->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4)
		return 0;
	return _materia[idx];
}

void Character::setName(std::string name)
{
	if (!this->_name.empty())
		std::cout << YELLOW << this->_name << CC
		          << " changed name to " << name << RST << std::endl;
	else
		std::cout << YELLOW << name << DC
		          << " has entered the game !" << RST << std::endl;
	this->_name = name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == 0)
		{
			std::cout << YELLOW << this->_name << MAGENTA
			          << " equipped materia of type " << m->getType()
			          << RST << std::endl;
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout << YELLOW << this->_name << RED
	          << " can't equip: no space left" << RST << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << YELLOW << this->_name << RED
		          << " can't unequip: slot " << idx << " invalid" << RST << std::endl;
		return ;
	}
	if (this->_materia[idx] == 0)
	{
		std::cout << YELLOW << this->_name << RED
		          << " can't unequip: slot " << idx << " already empty" << RST << std::endl;
		return ;
	}
	AMateria **tmp = new AMateria*[_numDropped + 1];
	for (int i = 0; i < _numDropped; i++)
		tmp[i] = _dropped[i];
	tmp[_numDropped] = this->_materia[idx];
	_numDropped++;
	delete[] _dropped;
	_dropped = tmp;

	this->_materia[idx] = 0;
	std::cout << CYAN << this->_name << GREEN
	          << " unequipped materia from slot " << idx
	          << RST << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << YELLOW << this->_name << RED
		          << " can't use: slot " << idx << " invalid" << RST << std::endl;
		return ;
	}
	if (this->_materia[idx] == 0)
	{
		std::cout << YELLOW << this->_name << RED
		          << " can't use: no materia in slot " << idx << RST << std::endl;
		return ;
	}
	std::cout << YELLOW << this->_name << " ";
	this->_materia[idx]->use(target);
}
