/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:40:19 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/11 12:33:19 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

t_map	*parse_map(char *file, t_settings *settings)
{
	int		fd;
	char	*line;
	t_map	*map;
	int		y;
	char	**values;
	int		width;
	int		x;
	char	**split_values;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = ft_getnline(file);
	map->width = 0;
	map->points = NULL;
	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points || map->height == 0)
		return ((free(map)), NULL);
	fd = open(file, O_RDONLY);
	y = 0;
	while ((line = get_next_line(fd)))
	{
		values = ft_split(line, ' ');
		width = 0;
		while (values[width])
			width++;
		if (y == 0)
			map->width = width;
		else if (width != map->width)
		{
			free(line);
			free_tab((void **)values);
			close(fd);
			free_map(map);
			return (NULL);
		}
		map->points[y] = malloc(sizeof(t_point) * map->width);
		if (!map->points[y])
		{
			free(line);
			free_tab((void **)values);
			free_map(map);
			close(fd);
			return (NULL);
		}
		x = 0;
		while (x < map->width)
		{
			split_values = ft_split(values[x], ',');
			if (split_values[1] != NULL)
			{
				map->points[y][x].z = ft_atoi(split_values[0]) * settings->z_scale;
				map->points[y][x].color = (unsigned int)strtol(split_values[1], NULL, 16);
			}
			else
			{
				map->points[y][x].z = ft_atoi(values[x]) * settings->z_scale;
				map->points[y][x].color = 0xFFFFFF;
			}
			map->points[y][x].x = x * settings->scale - map->width * settings->scale / 2 + settings->offset_x;
			map->points[y][x].y = y * settings->scale - map->height * settings->scale / 2 + settings->offset_y;
			free_tab((void **)split_values);
			x++;
		}
		y++;
		free(line);
		free_tab((void **)values);
	}
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
