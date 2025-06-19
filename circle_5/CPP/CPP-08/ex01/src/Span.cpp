/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:28:00 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/19 15:07:52 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"


Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw std::length_error("Span is full");
	}
	_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	size_t count = std::distance(begin, end);
	if (_numbers.size() + count > _maxSize) {
		throw std::length_error("Adding these numbers would exceed the maximum size of the span");
	}
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = static_cast<unsigned int>(-1);
	for (size_t i = 1; i < sorted.size(); ++i) {
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough elements to find a span");
	}
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(max - min);
}
