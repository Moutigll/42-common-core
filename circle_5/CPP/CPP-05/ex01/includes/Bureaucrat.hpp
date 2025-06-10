/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:34:26 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 22:06:24 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string	&getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return "\033[31mGrade too high!\033[0m";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return "\033[31mGrade too low!\033[0m";
				}
		};
	private:
		const std::string	_name;
		int					_grade;

		void	validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif