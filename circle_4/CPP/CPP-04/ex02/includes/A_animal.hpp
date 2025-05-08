/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:02:29 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/07 17:53:08 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

#include "Brain.hpp"

class A_animal
{
	protected:
		A_animal();
		A_animal(const std::string &type);
		A_animal(const A_animal &other);
		A_animal &operator=(const A_animal &other);

		std::string _type;
	public:
		virtual ~A_animal();

		virtual void makeSound(void) = 0;
};
#endif