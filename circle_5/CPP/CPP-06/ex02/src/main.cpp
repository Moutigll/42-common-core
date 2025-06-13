/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:47:12 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/13 10:58:18 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cerrno>
#include "../includes/Base.hpp"

Base*	generate(void) {
	int	rand_num = rand() % 3;

	if (rand_num == 0)
		return new A();
	else if (rand_num == 1)
		return new B();
	else
		return new C();
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
		return;
	} catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B\n";
		return;
	} catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C\n";
		return;
	} catch (std::exception &e) {}
	std::cout << "Unknown type\n";
}

int	main(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== Random identification tests ===" << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << "\nTest #" << i + 1 << ":" << std::endl;

		Base* obj = generate();

		std::cout << "identify(Base*): ";
		identify(obj);

		std::cout << "identify(Base&): ";
		identify(*obj);

		delete obj;
	}

	std::cout << "\n=== End of tests ===" << std::endl;
	return 0;
}
