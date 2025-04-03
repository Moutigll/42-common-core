/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/02 14:16:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"

int main() {
	// Default constructor
	Fixed a;
	std::cout << "Default constructed a: " << a << std::endl;

	// Constructing from float and integer
	Fixed b(5.05f);
	Fixed c(2);
	std::cout << "Float constructed b: " << b << std::endl;
	std::cout << "Integer constructed c: " << c << std::endl;

	// Multiplication operator
	Fixed d = b * c;
	std::cout << "b * c = " << d << std::endl;

	// Testing increment operators
	std::cout << "Pre-incrementing a: " << ++a << std::endl; // a is incremented before printing
	std::cout << "Post-incrementing a: " << a++ << std::endl; // a is printed before incrementing
	std::cout << "Value of a after increments: " << a << std::endl;

	// Testing decrement operators
	std::cout << "Pre-decrementing a: " << --a << std::endl; // a is decremented before printing
	std::cout << "Post-decrementing a: " << a-- << std::endl; // a is printed before decrementing
	std::cout << "Value of a after decrements: " << a << std::endl;

	// Testing arithmetic operations
	Fixed sum = b + c;
	Fixed diff = b - c;
	Fixed prod = b * c;
	Fixed quot = b / c;
	Fixed zero = Fixed(0);
	std ::cout << "b: " << b << " c: " << c << std::endl;
	std::cout << "b + c = " << sum << std::endl;
	std::cout << "b - c = " << diff << std::endl;
	std::cout << "b * c = " << prod << std::endl;
	std::cout << "b / c = " << quot << std::endl;
	Fixed divByZero = b / zero;
	std::cout << "b / 0 = " << divByZero << std::endl;

	// Testing comparison operators
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= c: " << (b >= c) << std::endl;
	std::cout << "b <= c: " << (b <= c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	// Edge case: Comparing equal values
	Fixed e(5.05f);
	std::cout << "b == e: " << (b == e) << std::endl;
	std::cout << "b != e: " << (b != e) << std::endl;
	std::cout << "b >= e: " << (b >= e) << std::endl;
	std::cout << "b <= e: " << (b <= e) << std::endl;

	// Testing min and max functions
	std::cout << "Min of b and c: " << Fixed::min(b, c) << std::endl;
	std::cout << "Max of b and c: " << Fixed::max(b, c) << std::endl;

	// Edge cases for min and max
	std::cout << "Min of b and e (equal values): " << Fixed::min(b, e) << std::endl;
	std::cout << "Max of b and e (equal values): " << Fixed::max(b, e) << std::endl;

	return 0;
}
