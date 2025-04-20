/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:38:48 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/20 04:33:38 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &other): _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) {
	(void)other;
	return *this;
}

Point::~Point() {}

Fixed Point::get_x(void) const {
	return this->_x;
}

Fixed Point::get_y(void) const {
	return this->_y;
}
