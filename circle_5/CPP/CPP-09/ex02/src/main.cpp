/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:42:27 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/28 00:52:51 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
		return 1;
	}

	std::vector<std::string> input(argv + 1, argv + argc);
	PmergeMe sorter;

	try {
		std::vector<int> numbers;
		sorter.parseInput(input, numbers);
		sorter.sortAndDisplay(numbers);
	} catch (const std::exception &e) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
