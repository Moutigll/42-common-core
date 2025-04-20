/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/20 04:31:41 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(2.0f, 2.0f);
	Point outside(10.0f, 10.0f);
	Point border(0.0f, 0.0f);

	std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "On the border: " << bsp(a, b, c, border) << std::endl;

	return 0;
}
