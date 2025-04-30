/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:19:12 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 15:22:52 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int	main(void)
{
	std::cout << "\033[34m--- Constructing Animals ---\033[0m" << std::endl;

	Animal* meta = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	std::cout << "\n\033[34m--- Testing makeSound() (Polymorphism) ---\033[0m" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n\033[34m--- Deleting Animals ---\033[0m" << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << "\n\033[34m--- Constructing WrongAnimals ---\033[0m" << std::endl;
	WrongAnimal* wrong_animal = new WrongAnimal();
	WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "\n\033[34m--- Testing makeSound() (Without virtual) ---\033[0m" << std::endl;
	wrong_animal->makeSound();
	wrong_cat->makeSound();

	std::cout << "\n\033[34m--- Deleting WrongAnimals ---\033[0m" << std::endl;
	delete wrong_animal;
	delete wrong_cat;

	return (0);
}
