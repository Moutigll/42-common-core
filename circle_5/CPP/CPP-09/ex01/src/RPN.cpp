/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:50:34 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/27 20:56:38 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

/**
 * @brief Checks if a character is a valid RPN operator
 * @param token Character to check
 * @return True if the character is +, -, *, or /
 */
bool RPN::isOperator(char token) {
	return token == '+' || token == '-' || token == '*' || token == '/';
}

/**
 * @brief Performs a basic arithmetic operation
 * @param a First operand
 * @param b Second operand
 * @param op Operator (+, -, *, /)
 * @return Result of the operation
 * @throws std::runtime_error for division by zero
 */
double RPN::calculate(double a, double b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': 
			if (b == 0) {
				throw std::runtime_error("Error: Division by zero");
			}
			return a / b;
		default:
			throw std::runtime_error("Error: Invalid operator");
	}
}

/**
 * @brief Evaluates an RPN expression
 * @param expression String containing the RPN expression
 * @return The result of the evaluation
 * @throws std::runtime_error for invalid expressions
 */
double RPN::evaluate(const std::string& expression) {
	std::stack<double> operands; // Stack to store operands

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		// If token is a single digit
		if (token.length() == 1 && isdigit(token[0])) {
			operands.push(token[0] - '0');
		} 
		// If token is an operator
		else if (token.length() == 1 && isOperator(token[0])) {
			if (operands.size() < 2) {
				throw std::runtime_error("Error: Not enough operands for operator");
			}
			
			double b = operands.top();
			operands.pop();
			double a = operands.top();
			operands.pop();
			
			operands.push(calculate(a, b, token[0]));
		} 
		// Invalid token
		else {
			throw std::runtime_error("Error: Invalid token in expression");
		}
	}

	if (operands.size() != 1) {
		throw std::runtime_error("Error: Invalid expression - too many operands remaining");
	}

	return operands.top();
}
