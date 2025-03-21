/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:14:47 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 17:16:24 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>
# include <string>

typedef std::string str;

class Weapon
{
	public:
		Weapon(str type);
		~Weapon(void);

		str const	&getType(void) const;
		void		setType(str type);

	private:
		str	_type;
};

#endif