/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:45:23 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/11 00:36:04 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Intern.hpp"

int	main(void) {
	try {
		Intern	intern;

		AForm*	form1 = intern.makeForm("shrubbery creation", "home");
		AForm*	form2 = intern.makeForm("robotomy request", "marvin");
		AForm*	form3 = intern.makeForm("presidential pardon", "arthur dent");

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		delete form1;
		delete form2;
		delete form3;

		AForm*	form4 = intern.makeForm("invalid form", "nobody");
		(void)form4;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
