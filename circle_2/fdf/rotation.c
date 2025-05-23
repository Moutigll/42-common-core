/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:56:05 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 16:22:38 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_point(t_point *point, double angle_x, double angle_y)
{
	double	temp_z;

	temp_z = point->y * sin(angle_x) + point->z * cos(angle_x);
	point->x = point->x * cos(angle_y) + temp_z * sin(angle_y);
	point->y = point->y * cos(angle_x) - point->z * sin(angle_x);
}

void	rotate_map(t_map *map,
	double angle_x, double angle_y, t_settings *settings)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = (int)((settings->scale * x
						- (settings->map->width * settings->scale) / 2)
					+ settings->scale / 2);
			map->points[y][x].y = (int)((settings->scale * y
						- (settings->map->height * settings->scale) / 2)
					+ settings->scale / 2);
			rotate_point(&map->points[y][x], angle_x, angle_y);
			map->points[y][x].x += settings->offset_x;
			map->points[y][x].y += settings->offset_y;
			x++;
		}
		y++;
	}
}
