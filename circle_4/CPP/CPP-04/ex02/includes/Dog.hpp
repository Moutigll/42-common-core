/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:14:56 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:47:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "A_animal.hpp"

class Dog: public A_animal
{
	public:
		Dog();
		Dog(const std::string &type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void		makeSound(void);
		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string &idea);

	private:
		Brain		*_brain;
};

#endif