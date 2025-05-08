/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:10:32 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 17:03:20 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"

void print_header(std::string const& title)
{
	std::cout << std::endl << GREEN << "=== " << title << " ===" << RST << std::endl;
}

int main()
{
	print_header("Learning Materia");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // Should be rejected

	print_header("Creating Character and Equipping Materia");
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); // Should be rejected, already 4 equipped

	print_header("Using Materia on another Character");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob); // ice
	me->use(1, *bob); // cure

	print_header("Using invalid indices");
	me->use(-1, *bob);
	me->use(4, *bob);

	print_header("Unequipping Materia");
	me->unequip(2); // Valid
	me->unequip(2); // Already empty
	me->unequip(10); // Invalid index

	print_header("Create unknown Materia");
	tmp = src->createMateria("fire");
	if (!tmp)
		std::cout << RED << "Unknown materia correctly returned nullptr." << RST << std::endl;

	print_header("Copy constructor test");
	Character original("original");
	original.equip(src->createMateria("ice"));
	Character copy(original);
	copy.setName("copy_from_original");
	copy.use(0, *bob);

	print_header("Assignment operator test");
	Character assigned("assigned");
	assigned = original;
	assigned.setName("assigned_copy");
	assigned.use(0, *bob);

	print_header("Cloning a materia manually");
	AMateria* ice1 = src->createMateria("ice");
	AMateria* ice2 = ice1->clone();
	delete ice1;
	ICharacter* clone_tester = new Character("clone_tester");
	clone_tester->equip(ice2);
	clone_tester->use(0, *bob);
	delete clone_tester;

	print_header("Create MateriaSource with no learned materia");
	IMateriaSource* empty_src = new MateriaSource();
	AMateria* null_mat = empty_src->createMateria("ice");
	if (!null_mat)
		std::cout << RED << "No materia learned, correctly returned nullptr." << RST << std::endl;
	delete empty_src;

	print_header("Testing dropped materia memory management");
	Character *drop_tester = new Character("drop_tester");
	drop_tester->equip(src->createMateria("ice"));
	drop_tester->equip(src->createMateria("cure"));
	drop_tester->equip(src->createMateria("ice"));
	drop_tester->equip(src->createMateria("cure"));

	drop_tester->use(0, *drop_tester); // Use before unequip

	drop_tester->unequip(1); // Unequip "cure"
	drop_tester->unequip(2); // Unequip "ice"
	drop_tester->unequip(3); // Unequip "cure"

	std::cout << BLUE << "Equipped after unequip:\n" << RST;
	for (int i = 0; i < 4; i++) {
		std::cout << "Slot " << i << ": " << (drop_tester->getMateria(i) ? "occupied" : "empty") << std::endl;
	}

	drop_tester->equip(src->createMateria("ice")); // Refill slots

	std::cout << BLUE << "Calling destructor, should clean dropped materia.\n" << RST;
	delete drop_tester;

	print_header("Destroying all");
	delete bob;
	delete me;
	delete src;

	return 0;
}