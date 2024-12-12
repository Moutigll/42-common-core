/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:56:05 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/12 18:16:03 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_point(t_point *point, double angle_x, double angle_y)
{
	double	temp_x;
	double	temp_y;

	temp_x = point->x * cos(angle_y) - point->z * sin(angle_y);
	temp_y = point->y * cos(angle_x) - point->z * sin(angle_x);
	point->x = temp_x;
	point->y = temp_y;
}

void	rotate_map(t_map *map, double angle_x, double angle_y, t_settings *settings)
{
	int		x;
	int		y;

	for (y = 0; y < map->height; y++)
	{
		for (x = 0; x < map->width; x++)
		{
			map->points[y][x].x = (int) ((settings->scale * x - (settings->map->width * settings->scale) / 2) + settings->scale / 2);
			map->points[y][x].y = (int) ((settings->scale * y - (settings->map->height * settings->scale) / 2) + settings->scale / 2);

			rotate_point(&map->points[y][x], angle_x, angle_y);
			map->points[y][x].x += settings->offset_x;
			map->points[y][x].y += settings->offset_y;
		}
	}
}