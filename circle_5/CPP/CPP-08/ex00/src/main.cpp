/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:32:53 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/17 15:33:02 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "../includes/easyfind.hpp"

int	main(void)
{
	std::vector<int>	v;
	std::list<int>		l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i * 2);
	}

	try
	{
		std::vector<int>::iterator	it = easyfind(v, 5);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Vector error: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator	it = easyfind(l, 3);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "List error: " << e.what() << std::endl;
	}
	return (0);
}
