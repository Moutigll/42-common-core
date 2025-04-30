/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:26:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 14:29:10 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") {
	std::cout << DC "WrongAnimal default constructor called" RST << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << PC "WrongAnimal parameterized constructor called" RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << CC "WrongAnimal copy constructor called" RST << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << A "WrongAnimal assignment operator called" RST << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << D "WrongAnimal destructor called" RST << std::endl;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "This wrong animal doesn't have a sound" << std::endl;
}