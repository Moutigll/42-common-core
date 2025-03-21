/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:17:45 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 17:17:58 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(str name);
		~HumanB(void);

		void	attack(void) const;
		void	setWeapon(Weapon &weapon);

	private:
		str		_name;
		Weapon	*_weapon;
};

#endif