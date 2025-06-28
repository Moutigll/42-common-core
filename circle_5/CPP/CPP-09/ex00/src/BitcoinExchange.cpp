/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 04:25:11 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/27 23:35:43 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->_exchangeRates = other._exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}
	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, valueStr;

		if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
			float value = std::strtof(valueStr.c_str(), NULL);
			_exchangeRates[date] = value;
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++) { // Check format YYYY-MM-DD
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30,
							31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

void	BitcoinExchange::evaluateInputFile(const std::string& filename) const {
	std::ifstream file(filename.c_str());
	std::string line;

	// Open the input file
	if (!file.is_open()) {
		std::cerr << "\033[31mError: could not open file.\033[0m" << std::endl;
		return;
	}

	std::getline(file, line); // Skip header line (e.g. "date | value")

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, value_str;

		// Check for correct delimiter " | "
		if (line.find(" | ") == std::string::npos) {
			std::cerr << "\033[31mError: bad input => " << line << "\033[0m" << std::endl;
			continue;
		}

		// Extract date and value from the line
		date = line.substr(0, line.find(" | "));
		value_str = line.substr(line.find(" | ") + 3);

		// Validate date format and existence
		if (!isValidDate(date)) {
			std::cerr << "\033[31mError: bad input => " << date << "\033[0m" << std::endl;
			continue;
		}

		// Convert value string to double and check for conversion errors
		char* end;
		double value = std::strtod(value_str.c_str(), &end);
		if (*end != '\0') {
			std::cerr << "\033[31mError: bad input => " << line << "\033[0m" << std::endl;
			continue;
		}

		// Check for negative or too large values
		if (value < 0) {
			std::cerr << "\033[31mError: not a positive number.\033[0m" << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "\033[31mError: too large a number.\033[0m" << std::endl;
			continue;
		}

		// Find closest available exchange rate on or before the given date
		std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

		// If exact date not found, use closest earlier date if available
		if (it == _exchangeRates.end() || it->first != date) {
			if (it == _exchangeRates.begin()) {
				std::cerr << "\033[31mError: no available rate for " << date << "\033[0m" << std::endl;
				continue;
			}
			--it;
		}

		// Display the converted value
		std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	}
}
