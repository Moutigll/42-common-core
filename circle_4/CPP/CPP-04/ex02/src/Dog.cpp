/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:18:04 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:55:07 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : A_animal("Dog") {
	std::cout << DC "Dog default constructor called" RST << std::endl;
	_brain = new Brain();
}

Dog::Dog(const std::string &type) : A_animal(type) {
	std::cout << PC "Dog parameterized constructor called" RST << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : A_animal(other) {
	std::cout << CC "Dog copy constructor called" RST << std::endl;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << A "Dog assignment operator called" RST << std::endl;
	if (this != &other) {
		A_animal::operator=(other);
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
