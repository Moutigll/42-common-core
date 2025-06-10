/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:57:18 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 22:08:37 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	validateGrade(_signGrade);
	validateGrade(_executeGrade);
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void Form::validateGrade(int grade) const {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, const Form &Form) {
	os << "Form: " << Form.getName()
	   << ", Signed: " << (Form.isSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << Form.getSignGrade()
	   << ", Execute Grade: " << Form.getExecuteGrade();
	return os;
}