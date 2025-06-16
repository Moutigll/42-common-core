/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:48:44 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/16 16:02:26 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(const T *array, std::size_t length, F func)
{
	if (!array || length == 0)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T, typename F>
void iter(T *array, std::size_t length, F func)
{
	if (!array || length == 0)
		return;
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif
