/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:56:06 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 15:19:56 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"


class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const &other);
	virtual ~Ice(void);
	Ice &operator=(Ice const &other);

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif