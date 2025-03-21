/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:24:58 by ele-lean          #+#    #+#             */
/*   Updated: 2025/03/21 16:48:33 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>
# include <string>

typedef std::string str;

class Zombie
{
	public:
		Zombie(str name);
		Zombie(void);
		~Zombie(void);

		void	announce(void) const;
		void	setName(str name);

	private:
		str	_name;
};

Zombie	*newZombie(str name);
Zombie	*zombieHorde(int N, str name);

#endif