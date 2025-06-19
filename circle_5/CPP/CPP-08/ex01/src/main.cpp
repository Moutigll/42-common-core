/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:53 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/19 15:11:25 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#define MAX_SIZE 10000000

#include "../includes/Span.hpp"

int main() {

	try {
		Span small(1);
		small.addNumber(42);
		std::cout << small.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception (shortestSpan with 1 element): " << e.what() << std::endl;
	}

	try {
		Span empty(0);
		std::cout << empty.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception (longestSpan with 0 element): " << e.what() << std::endl;
	}

	try {
		Span over(3);
		over.addNumber(10);
		over.addNumber(20);
		over.addNumber(30);
		over.addNumber(40);
	} catch (const std::exception &e) {
		std::cerr << "Exception (add too many): " << e.what() << std::endl;
	}
	
	try {
		Span sp(MAX_SIZE);
		std::vector<int> numbers;
		srand(static_cast<unsigned int>(time(0)));
		for (unsigned int i = 0; i < MAX_SIZE; ++i) {
			numbers.push_back(rand() % std::numeric_limits<int>::max());
		}
		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception (large span): " << e.what() << std::endl;
	}
	return 0;
}
