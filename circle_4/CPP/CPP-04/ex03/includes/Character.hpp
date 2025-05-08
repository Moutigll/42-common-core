/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:58:47 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 17:03:51 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(Character const &other);
		virtual ~Character();
		Character &operator=(Character const &other);

		std::string const	&getName() const;
		AMateria			*getMateria(int idx) const;
		void				setName(std::string name);
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_materia[4];
		AMateria	**_dropped;
		int			_numDropped;
};

#endif