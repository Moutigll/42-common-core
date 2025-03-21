/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:16:28 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 17:17:11 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(str name, Weapon &weapon);
		~HumanA(void);

		void	attack(void) const;

	private:
		str		_name;
		Weapon	&_weapon;
};

#endif