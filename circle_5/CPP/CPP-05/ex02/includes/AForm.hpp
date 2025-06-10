/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:57:09 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 19:54:25 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

/*
 * AForm abstract class represents a bureaucratic AForm that can be signed and executed.
 * It has a name, a sign grade, and an execute grade.
 * A AForm can be signed by a Bureaucrat if their grade is high enough.
 * Once signed, it can be executed by a Bureaucrat with the appropriate grade.
 */
class AForm {
	public:
		/*
		 * Constructor
		 * Initializes a AForm with a name, sign grade, and execute grade.
		 * Throws exceptions if the grades are invalid.
		 * @param name The name of the AForm.
		 * @param signGrade The grade required to sign the AForm.
		 * @param executeGrade The grade required to execute the AForm.
		*/
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor) const;
		virtual void	executeAction() const = 0;

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

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return "\033[31mForm not signed!\033[0m";
				}
		};
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

		void	validateGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif