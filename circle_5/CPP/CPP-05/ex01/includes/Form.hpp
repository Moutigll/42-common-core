/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:57:09 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 22:06:12 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

/*
 * Form class represents a bureaucratic Form that can be signed and executed.
 * It has a name, a sign grade, and an execute grade.
 * A Form can be signed by a Bureaucrat if their grade is high enough.
 * Once signed, it can be executed by a Bureaucrat with the appropriate grade.
 */
class Form {
	public:
		/*
		 * Constructor
		 * Initializes a Form with a name, sign grade, and execute grade.
		 * Throws exceptions if the grades are invalid.
		 * @param name The name of the Form.
		 * @param signGrade The grade required to sign the Form.
		 * @param executeGrade The grade required to execute the Form.
		*/
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		virtual ~Form();

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(const Bureaucrat &executor) const;

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
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

		void	validateGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif