/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:50:33 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 15:51:33 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_map(t_settings *settings, t_map *map)
{
	int	x;
	int	y;

	fill_rect(settings->img, 0, 0, WIDTH, HEIGHT, 0x00000000);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(settings, map->points[y][x], map->points[y][x + 1]);
			if (y < map->height - 1)
				draw_line(settings, map->points[y][x], map->points[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	adjust_points(t_map *map, int y, int x, double scale_factor)
{
	if (y >= map->height)
		return ;
	if (x >= map->width)
		return (adjust_points(map, y + 1, 0, scale_factor));
	map->points[y][x].z *= scale_factor;
	adjust_points(map, y, x + 1, scale_factor);
}
