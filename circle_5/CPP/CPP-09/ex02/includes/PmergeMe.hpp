/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:03:05 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/28 02:51:09 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <vector>
#include <string>
#include <utility>


/**
 * @class PmergeMe
 * @brief Implements the Ford-Johnson merge-insertion sort algorithm using vector and deque containers
 */
class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);

	/**
	 * @brief Main sorting and display function
	 * @param input The sequence of positive integers to sort
	 */
	void sortAndDisplay(const std::vector<int> &input);
	
	/**
	 * @brief Parses the input strings into integers
	 * @param input The input strings to parse
	 * @param numbers Output vector for parsed numbers
	 */
	void parseInput(const std::vector<std::string> &input, std::vector<int> &numbers);
private:

	/**
	 * @brief Merge-insert sort implementation for vector
	 * @param vec The vector to sort
	 */
	void mergeInsertSortVector(std::vector<int> &vec);

	/**
	 * @brief Inserts an element into the correct position in the main chain for vector
	 * @param mainChain The main sorted chain
	 * @param element The element to insert
	 */
	void insertElementVector(std::vector<int> &mainChain, int element);

	// Deque implementation
	/**
	 * @brief Merge-insert sort implementation for deque
	 * @param deq The deque to sort
	 */
	void mergeInsertSortDeque(std::deque<int> &deq);

	/**
	 * @brief Merges sorted pairs into main chain for deque
	 * @param pairs The sorted pairs to merge
	 * @param result The resulting sorted deque
	 */
	void mergePairsDeque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &result);

	/**
	 * @brief Inserts an element into the correct position in the main chain for deque
	 * @param mainChain The main sorted chain
	 * @param element The element to insert
	 */
	void insertElementDeque(std::deque<int> &mainChain, int element);

	/**
	 * @brief Displays the sorting results and timing information
	 * @param input The original unsorted sequence
	 * @param sortedVec The sorted vector
	 * @param sortedDeq The sorted deque
	 * @param vecTime Time taken for vector sort (microseconds)
	 * @param deqTime Time taken for deque sort (microseconds)
	 */
	void displayResults(const std::vector<int> &input,
					   const std::vector<int> &sortedVec,
					   double vecTime, double deqTime);
};

#endif
