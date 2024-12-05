/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:56:05 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/05 06:04:30 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_point(t_point *point, double angle_x,
	double angle_y, double angle_z)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;

	temp_x = point->x * cos(angle_y) * cos(angle_z)
		- point->y * sin(angle_z) * cos(angle_y)
		+ point->z * sin(angle_y);
	temp_y = point->x * (cos(angle_z) * sin(angle_x) * sin(angle_y)
			+ sin(angle_z) * cos(angle_x))
		+ point->y * (cos(angle_x) * cos(angle_z)
			- sin(angle_x) * sin(angle_y) * sin(angle_z))
		- point->z * cos(angle_y) * sin(angle_x);
	temp_z = point->x * (sin(angle_x) * sin(angle_z)
			- cos(angle_x) * cos(angle_z) * sin(angle_y))
		+ point->y * (cos(angle_z) * sin(angle_x)
			+ cos(angle_x) * sin(angle_y) * sin(angle_z))
		+ point->z * cos(angle_y) * cos(angle_x);
	point->x = temp_x;
	point->y = temp_y;
	point->z = temp_z;
}

void	apply_rotation(t_list *points, double angle_x,
	double angle_y, double angle_z)
{
	t_list	*current;
	t_point	*point;

	current = points;
	while (current)
	{
		point = (t_point *)current->content;
		rotate_point(point, angle_x, angle_y, angle_z);
		current = current->next;
	}
}
