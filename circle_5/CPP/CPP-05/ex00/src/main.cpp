/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:45:23 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 18:53:16 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	a("Alice", 1); // grade max
		Bureaucrat	b("Bob", 150); // grade min
		Bureaucrat	c("Charlie", 42);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << "Incrementing Charlie..." << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;

		std::cout << "Decrementing Bob..." << std::endl;
		b.decrementGrade(); // Should throw
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Now trying to create a bureaucrat with grade 0..." << std::endl;
	try {
		Bureaucrat fail("FailGuy", 0); // Should throw
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Now trying to create a bureaucrat with grade 200..." << std::endl;
	try {
		Bureaucrat fail2("FailGuy2", 200); // Should throw
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
