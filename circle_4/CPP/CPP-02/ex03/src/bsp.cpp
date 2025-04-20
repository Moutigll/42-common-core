/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:39:01 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/20 04:29:02 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	cross(Point const &a, Point const &b, Point const &c) {
	Fixed abx = b.get_x() - a.get_x();
	Fixed aby = b.get_y() - a.get_y();
	Fixed acx = c.get_x() - a.get_x();
	Fixed acy = c.get_y() - a.get_y();
	return (abx * acy - aby * acx);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	cp1 = cross(a, b, point);
	Fixed	cp2 = cross(b, c, point);
	Fixed	cp3 = cross(c, a, point);

	bool	has_neg = (cp1 < 0) || (cp2 < 0) || (cp3 < 0);
	bool	has_pos = (cp1 > 0) || (cp2 > 0) || (cp3 > 0);

	return !(has_neg && has_pos);
}
