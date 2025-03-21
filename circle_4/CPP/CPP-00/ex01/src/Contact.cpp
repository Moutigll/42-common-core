/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:41 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/20 15:22:58 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void		Contact::setFirstName(str firstName)
{
	this->firstName = firstName;
}

str	Contact::getFirstName(void) const
{
	return (this->firstName);
}

void		Contact::setLastName(str lastName)
{
	this->lastName = lastName;
}

str	Contact::getLastName(void) const
{
	return (this->lastName);
}

void		Contact::setNickname(str nickname)
{
	this->nickname = nickname;
}

str	Contact::getNickname(void) const
{
	return (this->nickname);
}

void		Contact::setPhoneNumber(str phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
str	Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

void		Contact::setDarkestSecret(str darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

str	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}