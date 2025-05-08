/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:03:30 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:55:00 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : A_animal("Cat") {
	std::cout << DC "Cat default constructor called" RST << std::endl;
	_brain = new Brain();
}

Cat::Cat(const std::string &type) : A_animal(type) {
	std::cout << PC "Cat parameterized constructor called" RST << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : A_animal(other) {
	std::cout << CC "Cat copy constructor called" RST << std::endl;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << A "Cat assignment operator called" RST << std::endl;
	if (this != &other) {
		A_animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << D "Cat destructor called" RST << std::endl;
	delete _brain;
}

void Cat::makeSound(void) {
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea(int index) const {
	return _brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string &idea) {
	_brain->setIdea(index, idea);
}
