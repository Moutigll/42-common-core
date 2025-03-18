/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:22:34 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/18 22:09:03 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : maxContacts(8), nbContacts(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(void)
{
	str firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	system("clear");

	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: All fields must be filled!" << std::endl;
		return ;
	}

	int index = nbContacts < maxContacts ? nbContacts : oldestIndex;

	if (nbContacts >= maxContacts)
	{
		std::cout << "Phonebook is full, replacing the oldest contact." << std::endl;
		oldestIndex = (oldestIndex + 1) % maxContacts;
	}
	else
	{
		nbContacts++;
	}

	contacts[index].setFirstName(firstName);
	contacts[index].setLastName(lastName);
	contacts[index].setNickname(nickname);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(darkestSecret);

	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::displayContacts(void) const
{
	if (nbContacts == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < nbContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
				  << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
				  << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::searchContact(void) const
{
	int index;

	std::cout << "Enter the index of the contact you want to see: ";
	std::cin >> index;
	std::cin.ignore();

	if (index < 0 || index >= nbContacts)
	{
		std::cout << "Error: Invalid index!" << std::endl;
		return ;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}