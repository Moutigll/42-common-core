/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:57:38 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/18 19:10:47 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.searchContact();
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}