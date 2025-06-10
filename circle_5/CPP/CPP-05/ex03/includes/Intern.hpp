/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:16:23 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/11 00:31:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class UnknownFormException : public std::exception {
	public:
		const char *what() const throw() {
			return "\033[31mUnknown form type!\033[0m";
		}
	};

	private:
		AForm *createShrubberyCreationForm(const std::string &target) const;
		AForm *createRobotomyRequestForm(const std::string &target) const;
		AForm *createPresidentialPardonForm(const std::string &target) const;
};

#endif