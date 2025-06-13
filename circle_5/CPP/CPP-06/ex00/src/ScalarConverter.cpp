/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 04:46:59 by moutig            #+#    #+#             */
/*   Updated: 2025/06/13 05:14:28 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static bool	isChar(const std::string& str) {
	return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

static bool	isInt(const std::string& str) {
	char*	end;

	errno = 0;
	long	val = std::strtol(str.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (errno == ERANGE) // Check overflow/underflow
		return false;
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		return false;
	return true;
}

static bool	isFloat(const std::string& str) {
	char*	end;
	std::strtof(str.c_str(), &end);
	return (*end == 'f' && end == str.c_str() + str.length() - 1);
}

static bool	isDouble(const std::string& str) {
	char*	end;
	std::strtod(str.c_str(), &end);
	return *end == '\0';
}

static bool	isSpecialFloat(const std::string& str) {
	return (str == "nanf" || str == "+inff" || str == "-inff");
}

static bool	isSpecialDouble(const std::string& str) {
	return (str == "nan" || str == "+inf" || str == "-inf");
}

void	ScalarConverter::convert(const std::string& literal) {
	std::cout << std::fixed << std::setprecision(1); // Set precision for float and double output

	if (isChar(literal)) {
		char c = literal[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n"; // Upcast to int, from 8bits to 32bits
		std::cout << "float: " << static_cast<float>(c) << "f\n"; // Upcast to float, from 8bits to 32bits
		std::cout << "double: " << static_cast<double>(c) << "\n"; // Upcast to double, from 8bits to 64bits
	}
	else if (isInt(literal)) {
		int i = std::atoi(literal.c_str());
		if (i >= 32 && i <= 126)
			std::cout << "char: '" << static_cast<char>(i) << "'\n"; // Downcast to char, precision lost
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << static_cast<float>(i) << "f\n"; // Upcast to float
		std::cout << "double: " << static_cast<double>(i) << "\n"; // Upcast to double, 32 -> 64 bits
	}
	else if (isFloat(literal) || isSpecialFloat(literal)) {
		float f = std::strtof(literal.c_str(), NULL);
		if (std::isnan(f) || std::isinf(f))
			std::cout << "char: impossible\nint: impossible\n";
		else {
			if (f >= 32 && f <= 126)
				std::cout << "char: '" << static_cast<char>(f) << "'\n"; // Downcast
			else
				std::cout << "char: Non displayable\n";
			std::cout << "int: " << static_cast<int>(f) << "\n"; // Downcast to int, precision lost
		}
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << static_cast<double>(f) << "\n"; // Upcast to double, 32 -> 64 bits
	}
	else if (isDouble(literal) || isSpecialDouble(literal)) {
		double d = std::strtod(literal.c_str(), NULL);
		if (std::isnan(d) || std::isinf(d))
			std::cout << "char: impossible\nint: impossible\n";
		else {
			if (d >= 32 && d <= 126)
				std::cout << "char: '" << static_cast<char>(d) << "'\n";
			else
				std::cout << "char: Non displayable\n";
			if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
				d > static_cast<double>(std::numeric_limits<int>::max())) {
				std::cout << "int: impossible\n";
			} else {
				std::cout << "int: " << static_cast<int>(d) << "\n"; // Downcast to int, precision lost
			}
		}
		std::cout << "float: " << static_cast<float>(d) << "f\n"; // Downcast to float, precision lost 
		std::cout << "double: " << d << "\n";
	}
	else {
		std::cout << "Error: Invalid literal.\n";
	}
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
