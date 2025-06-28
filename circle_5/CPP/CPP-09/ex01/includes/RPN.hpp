/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:46:39 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/27 20:50:53 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <string>

/**
 * @class RPN
 * @brief Calculator for Reverse Polish Notation expressions
 */
class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	/**
	 * @brief Evaluate an RPN expression
	 * @param expression The RPN expression to evaluate
	 * @return The result of the calculation
	 * @throw std::runtime_error If the expression is invalid
	 */
	double evaluate(const std::string& expression);

private:
	/**
	 * @brief Check if a token is a valid operator
	 * @param token The token to check
	 * @return True if the token is an operator, false otherwise
	 */
	bool isOperator(char token);

	/**
	 * @brief Perform a calculation with two operands and an operator
	 * @param a First operand
	 * @param b Second operand
	 * @param op Operator
	 * @return The result of the operation
	 * @throw std::runtime_error If division by zero occurs
	 */
	double calculate(double a, double b, char op);
};

#endif // RPN_HPP
