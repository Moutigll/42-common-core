/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:57:38 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/25 15:01:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "Error: Invalid input!" << std::endl;
			return (1);
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.searchContact();
		}
		else if (command.empty())
			std::cout << "No command provided!" << std::endl;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}