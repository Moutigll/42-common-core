/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:00:45 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/16 19:05:06 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../includes/Array.hpp"

int main()
{
	try {
		Array<int> a(5);

		for (std::size_t i = 0; i < a.size(); ++i)
			a[i] = static_cast<int>(i * 10);

		std::cout << "Array a: ";
		for (std::size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << "\n";

		Array<int> b = a;
		b[0] = 999;
		std::cout << "Modified b[0], a[0] still: " << a[0] << "\n";
		std::cout << "Access out of bounds: ";
		std::cout << a[42] << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
