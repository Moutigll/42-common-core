/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:08:47 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:46:40 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "A_animal.hpp"

class Cat: public A_animal
{
	public:
		Cat();
		Cat(const std::string &type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		void		makeSound(void);
		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string &idea);

	private:
		Brain		*_brain;
};

#endif