/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:19:12 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:56:57 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main(void)
{
	const int		size = 4;
	int				k;
	A_animal		*animals[size];
	Cat				original;
	Cat				copy;
	Dog				dog1;
	Dog				dog2;

	std::cout << YELLOW << "Basic polymorphic deletion test:" << RST << std::endl;
	const A_animal	*j = new Dog();
	const A_animal	*i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl << YELLOW << "Array of Animals test:" << RST << std::endl;

	k = 0;
	while (k < size)
	{
		if (k < size / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
		k++;
	}

	k = 0;
	while (k < size)
	{
		delete animals[k];
		k++;
	}

	std::cout << std::endl << YELLOW << "Deep copy test:" << RST << std::endl;
	original.setIdea(0, "chase laser");
	original.setIdea(1, "knock things off table");

	copy = original;

	std::cout << GREEN << "Original idea[0]: " << original.getIdea(0) << RST << std::endl;
	std::cout << BLUE << "Copy idea[0]:     " << copy.getIdea(0) << RST << std::endl;

	copy.setIdea(0, "sleep on laptop");

	std::cout << GREEN << "Original idea[0] after copy modified: " << original.getIdea(0) << RST << std::endl;
	std::cout << BLUE << "Copy idea[0] after modification:       " << copy.getIdea(0) << RST << std::endl;

	std::cout << std::endl << YELLOW << "Assignment deep copy test:" << RST << std::endl;
	dog1.setIdea(0, "fetch ball");
	dog2 = dog1;

	std::cout << GREEN << "Dog1 idea[0]: " << dog1.getIdea(0) << RST << std::endl;
	std::cout << BLUE << "Dog2 idea[0]: " << dog2.getIdea(0) << RST << std::endl;

	dog2.setIdea(0, "dig hole");

	std::cout << GREEN << "Dog1 idea[0] after Dog2 modified: " << dog1.getIdea(0) << RST << std::endl;
	std::cout << BLUE << "Dog2 idea[0] after modification:  " << dog2.getIdea(0) << RST << std::endl;

	return (0);
}