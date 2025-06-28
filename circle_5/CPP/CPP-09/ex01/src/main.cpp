/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:52:30 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/27 20:53:13 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>
#include <stdexcept>

/**
 * Usage: ./RPN "RPN expression"
 * Example: ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        double result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
