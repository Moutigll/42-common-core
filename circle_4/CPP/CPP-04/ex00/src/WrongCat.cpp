/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:29:28 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 14:29:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << DC "WrongCat default constructor called" RST << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type) {
	std::cout << PC "WrongCat parameterized constructor called" RST << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << CC "WrongCat copy constructor called" RST << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << A "WrongCat assignment operator called" RST << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << D "WrongCat destructor called" RST << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow! (WrongCat)" << std::endl;
}
