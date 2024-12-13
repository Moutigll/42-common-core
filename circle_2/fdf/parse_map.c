/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:40:19 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 16:44:44 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

t_map	*init_map(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = ft_getnline(file);
	map->width = 0;
	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points || map->height == 0)
		return (free(map), NULL);
	map->z_min = 0;
	map->z_max = 0;
	return (map);
}

int	parse_point(t_point *point, char *value, t_settings *settings, t_map *map)
{
	char	**split_values;

	split_values = ft_split(value, ',');
	if (!split_values)
		return (0);
	if (split_values[1])
	{
		point->z = (int)ft_atoi(split_values[0]) * settings->z_scale;
		point->color = (unsigned int)strtol(split_values[1], NULL, 16);
	}
	else
	{
		point->z = (int)ft_atoi(value) * settings->z_scale;
		point->color = 0xFFFFFF;
	}
	if (point->z < map->z_min)
		map->z_min = point->z;
	else if (point->z > map->z_max)
		map->z_max = point->z;
	point->x = (int)(settings->scale * point->x - map->width
			* settings->scale / 2 + settings->offset_x);
	point->y = (int)(settings->scale * point->y - map->height
			* settings->scale / 2 + settings->offset_y);
	free_tab((void **)split_values);
	return (1);
}

int	parse_line(t_map *map, char *line, int y, t_settings *settings)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (!values || ((y != 0 && ft_tablen((void **)values) != map->width)))
		return (free_tab((void **)values), 0);
	if (y == 0)
		map->width = ft_tablen((void **)values);
	map->points[y] = malloc(sizeof(t_point) * map->width);
	if (!map->points[y])
		return (free_tab((void **)values), 0);
	x = 0;
	while (x < map->width)
	{
		if (!parse_point(&map->points[y][x], values[x], settings, map))
			return (free_tab((void **)values), 0);
		x++;
	}
	free_tab((void **)values);
	return (1);
}

t_map	*parse_map(char *file, t_settings *settings)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		y;

	map = init_map(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!parse_line(map, line, y++, settings))
			return ((free(line)), (free_map(map)), (close(fd)), NULL);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

void	free_map(t_map *map)
{
	int	y;

	if (map)
	{
		y = 0;
		while (y < map->height)
		{
			free(map->points[y]);
			y++;
		}
		free(map->points);
		free(map);
	}
}
