/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:45:23 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 22:08:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void) {
	try {
		// Bureaucrats with various grades
		Bureaucrat bob("Bob", 100);
		Bureaucrat alice("Alice", 1);
		Bureaucrat tom("Tom", 150);

		// Forms with various signing requirements
		Form taxForm("Tax Form", 50, 75);
		Form topSecret("Top Secret", 1, 1);
		Form simpleForm("Simple Form", 150, 150);

		// Print all info
		std::cout << bob << std::endl;
		std::cout << alice << std::endl;
		std::cout << tom << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << topSecret << std::endl;
		std::cout << simpleForm << std::endl;

		std::cout << "\n=== Signing Attempts ===\n" << std::endl;

		// Attempt to sign forms
		bob.signForm(taxForm);        // Should fail
		alice.signForm(taxForm);      // Should succeed
		tom.signForm(simpleForm);     // Should succeed
		tom.signForm(topSecret);      // Should fail

		std::cout << "\n=== Final Form Status ===\n" << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << topSecret << std::endl;
		std::cout << simpleForm << std::endl;

		// Invalid form (grade too high or too low)
		std::cout << "\n=== Invalid Form Creation ===\n" << std::endl;
		Form badForm("Invalid", 0, 50); // Should throw GradeTooHighException
		std::cout << badForm << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
