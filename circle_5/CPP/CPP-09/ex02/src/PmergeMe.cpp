/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:03:30 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/28 02:56:01 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

// Constructors
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	(void)other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

void PmergeMe::parseInput(const std::vector<std::string> &input, std::vector<int> &numbers) {
	for (size_t i = 0; i < input.size(); ++i) {
		std::stringstream ss(input[i]);
		int num;
		ss >> num;
		numbers.push_back(num);
	}
}

// Vector implementation
void PmergeMe::mergeInsertSortVector(std::vector<int> &vec) {
	if (vec.size() <= 1) return;

	std::vector<std::pair<int, int> > pairs; // Create pairs of elements
	bool hasStraggler = (vec.size() % 2 != 0); // Check if there's an odd element
	int straggler = hasStraggler ? vec.back() : 0; // Extract the straggler if exists

	// Create pairs
	for (size_t i = 0; i < vec.size() - hasStraggler; i += 2) { // Iterate over the numbers inserting them in sorted pairs in the vector pairs
		if (vec[i] < vec[i + 1]) { // If the first is smaller
			pairs.push_back(std::make_pair(vec[i], vec[i + 1])); // Insert a new pair with [i, i + 1]
		} else {
			pairs.push_back(std::make_pair(vec[i + 1], vec[i])); // Insert a new pair with [i + 1, i]
		}
	}

	// Recursively sort the larger elements
	std::vector<int> largerElements; // A new vector to hold the larger elements of each pair
	for (size_t i = 0; i < pairs.size(); ++i) { // Iterate over the pairs vector
		largerElements.push_back(pairs[i].second);
	}
	mergeInsertSortVector(largerElements); // Sort the larger elements recursively

	for (size_t i = 0; i < pairs.size(); ++i) {
		insertElementVector(largerElements, pairs[i].first); // Insert the second element of each pair into the largerElements vector
	}

	if (hasStraggler)
		insertElementVector(largerElements, straggler);

	vec = largerElements;
}

void PmergeMe::insertElementVector(std::vector<int> &mainChain, int element) {
	std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), element); // Return an iterator to the first element that is not less than element
	mainChain.insert(it, element); // Insert the element at the found position
}

// Deque implementation (similar to vector but using deque)
void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq) {
	if (deq.size() <= 1) return;

	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = (deq.size() % 2 != 0);
	int straggler = hasStraggler ? deq.back() : 0;

	for (size_t i = 0; i < deq.size() - hasStraggler; i += 2) {
		if (deq[i] < deq[i + 1]) {
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		} else {
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
		}
	}

	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); ++i) {
		largerElements.push_back(pairs[i].second);
	}
	mergeInsertSortDeque(largerElements);

	for (size_t i = 0; i < pairs.size(); ++i) {
		insertElementDeque(largerElements, pairs[i].first);
	}

	if (hasStraggler)
		insertElementDeque(largerElements, straggler);

	deq = largerElements;
}

void PmergeMe::mergePairsDeque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &result) {
	if (pairs.empty()) return;

	result.push_back(pairs[0].first);
	result.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); ++i) {
		result.push_back(pairs[i].second);
		insertElementDeque(result, pairs[i].first);
	}
}

void PmergeMe::insertElementDeque(std::deque<int> &mainChain, int element) {
	std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), element);
	mainChain.insert(it, element);
}

// Display results
void PmergeMe::displayResults(const std::vector<int> &input, 
							   const std::vector<int> &sortedVec, 
							   double vecTime, double deqTime) {
	std::cout << "Before: ";
	for (size_t i = 0; i < input.size(); ++i) {
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < sortedVec.size(); ++i) {
		std::cout << sortedVec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << input.size() 
			  << " elements with std::vector: " << std::fixed << std::setprecision(5) 
			  << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of " << input.size() 
			  << " elements with std::deque: " << std::fixed << std::setprecision(5) 
			  << deqTime << " us" << std::endl;
}

void PmergeMe::sortAndDisplay(const std::vector<int> &input) {
	if (input.empty()) return;

	// Vector implementation
	std::vector<int> vec = input;
	clock_t start = clock();
	mergeInsertSortVector(vec);
	clock_t end = clock();
	double vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	// Deque implementation
	std::deque<int> deq(input.begin(), input.end());
	start = clock();
	mergeInsertSortDeque(deq);
	end = clock();
	double deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	displayResults(input, vec, vecTime, deqTime);
}
