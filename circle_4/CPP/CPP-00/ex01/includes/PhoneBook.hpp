/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:07:37 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/20 15:22:38 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>
# include <sstream>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	displayContacts(void) const;
		void	searchContact(void) const;

	private:
		const int	maxContacts;
		int			nbContacts;
		int			oldestIndex;
		Contact		contacts[8];
};

#endif