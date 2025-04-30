/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:18:04 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 15:37:56 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << DC "Dog default constructor called" RST << std::endl;
	_brain = new Brain();
}

Dog::Dog(const std::string &type) : Animal(type) {
	std::cout << PC "Dog parameterized constructor called" RST << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << CC "Dog copy constructor called" RST << std::endl;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << A "Dog assignment operator called" RST << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << D "Dog destructor called" RST << std::endl;
	delete _brain;
}

void Dog::makeSound(void) {
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const {
	return _brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string &idea) {
	_brain->setIdea(index, idea);
}
