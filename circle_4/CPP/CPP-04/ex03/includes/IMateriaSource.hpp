/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:51:55 by ele-lean          #+#    #+#             */
/*   Updated: 2025/05/08 15:11:34 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_H
#define IMATERIA_H

#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}

		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(std::string const& type) = 0;
};

#endif