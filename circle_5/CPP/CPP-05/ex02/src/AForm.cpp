/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:57:18 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/10 21:48:07 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	validateGrade(_signGrade);
	validateGrade(_executeGrade);
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::validateGrade(int grade) const {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _executeGrade) {
		throw GradeTooLowException();
	}
	executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os << "AForm: " << AForm.getName()
	   << ", Signed: " << (AForm.isSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << AForm.getSignGrade()
	   << ", Execute Grade: " << AForm.getExecuteGrade();
	return os;
}