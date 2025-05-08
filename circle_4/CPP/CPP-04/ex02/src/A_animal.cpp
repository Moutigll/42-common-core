/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:29:46 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:46:59 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A_animal.hpp"

A_animal::A_animal() : _type("Unknown")
{
	std::cout << "A_animal default constructor called" << std::endl;
}

A_animal::A_animal(const std::string &type) : _type(type)
{
	std::cout << "A_animal parameterized constructor called" << std::endl;
}

A_animal::A_animal(const A_animal &other) : _type(other._type)
{
	std::cout << "A_animal copy constructor called" << std::endl;
}

A_animal &A_animal::operator=(const A_animal &other)
{
	std::cout << "A_animal assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

A_animal::~A_animal()
{
	std::cout << "A_animal destructor called" << std::endl;
}
