/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:45:23 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 21:45:03 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat				boss("Boss", 1);
	Bureaucrat				junior("Junior", 150);
	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		robot("Marvin");
	PresidentialPardonForm	pardon("Arthur");

	std::cout << "\n--- Trying to execute unsigned form ---\n";
	try {
		boss.executeForm(shrub);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Signing forms with junior (should fail) ---\n";
	try {
		junior.signForm(shrub);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Signing forms with boss ---\n";
	try {
		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Junior tries to execute forms (should fail) ---\n";
	junior.executeForm(shrub);
	junior.executeForm(robot);
	junior.executeForm(pardon);

	std::cout << "\n--- Boss executes all forms (should succeed) ---\n";
	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	std::cout << "\n--- Test completed ---\n";
	return 0;
}