/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:42:33 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/20 04:41:57 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}


// Operators
//	Comparison operators
bool Fixed::operator>(const Fixed &other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed &other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed &other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed &other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed &other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed &other) const { return _rawBits != other._rawBits; }

//	Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const { return Fixed(toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { 
	if (other._rawBits == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	return Fixed(toFloat() / other.toFloat());
}

//	Increment and decrement operators
Fixed &Fixed::operator++() { // Pre-incrementation
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) { // Post-incrementation
	Fixed temp(*this);
	_rawBits++;
	return temp;
}

Fixed &Fixed::operator--() { // Pre-decrementation
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) { // Post-decrementation
	Fixed temp(*this);
	_rawBits--;
	return temp;
}

//	Static min and max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
