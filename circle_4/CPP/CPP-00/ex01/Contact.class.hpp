/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:23:44 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/18 18:13:35 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

typedef std::string str;

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void	setFirstName(str firstName);
		str		getFirstName(void) const;

		void	setLastName(str lastName);
		str		getLastName(void) const;

		void	setNickname(str nickname);
		str		getNickname(void) const;

		void	setPhoneNumber(str phoneNumber);
		str		getPhoneNumber(void) const;

		void	setDarkestSecret(str darkestSecret);
		str		getDarkestSecret(void) const;

	private:
		str	firstName;
		str	lastName;
		str	nickname;
		str	phoneNumber;
		str	darkestSecret;
};

#endif