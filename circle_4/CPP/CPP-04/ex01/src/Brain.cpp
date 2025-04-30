/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:53:01 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 14:54:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << DC "Brain default constructor called" RST << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << CC "Brain copy constructor called" RST << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << A "Brain assignment operator called" RST << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << D "Brain destructor called" RST << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		return "Invalid index";
	}
	return _ideas[index];
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index < 0 || index >= 100) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	_ideas[index] = idea;
}
