/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:50:50 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/16 16:08:57 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/iter.hpp"

void printInt(int& x)
{
	std::cout << x << ' ';
}

void incrementInt(int& x)
{
	++x;
}

void printChar(const char& c)
{
	if (c >= 32 && c <= 126)
	std::cout << c << ' ';
}

void testIntArray()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::size_t len = sizeof(arr) / sizeof(*arr);

	std::cout << "Original int array: ";
	iter(arr, len, printInt);
	std::cout << '\n';

	iter(arr, len, incrementInt);

	std::cout << "After incrementing: ";
	iter(arr, len, printInt);
	std::cout << "\n\n";
}

// Test with const char array (read-only)
void testConstCharArray()
{
	const char msg[] = "Hello, world!";
	std::size_t len = sizeof(msg) - 1; // exclude null terminator

	std::cout << "Const char array: ";
	iter(msg, len, printChar);
	std::cout << '\n';
}

int main()
{
	testIntArray();
	testConstCharArray();
	return 0;
}
