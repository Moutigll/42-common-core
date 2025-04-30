/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:06:38 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 15:10:10 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : _type("Unknown") {
	std::cout << DC "Animal default constructor called" RST << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << PC "Animal parameterized constructor called" RST << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << CC "Animal copy constructor called" RST << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << A "Animal assignment operator called" RST << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << D "Animal destructor called" RST << std::endl;
}
