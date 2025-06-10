/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:16:18 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/11 00:35:17 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}

Intern::~Intern() {}

AForm	*Intern::createShrubberyCreationForm(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createRobotomyRequestForm(const std::string &target) const {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createPresidentialPardonForm(const std::string &target) const {
	return new PresidentialPardonForm(target);
}


AForm*	Intern::makeForm(const std::string& name, const std::string& target) const {
	typedef AForm* (Intern::*formFunc)(const std::string&) const;

	const std::string	names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	formFunc	funcs[] = {
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm,
		&Intern::createShrubberyCreationForm
	};

	for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); ++i) {
		if (name == names[i]) {
			return (this->*funcs[i])(target);
		}
	}
	throw UnknownFormException();
}
