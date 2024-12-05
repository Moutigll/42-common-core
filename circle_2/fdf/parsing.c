/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:53:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/05 19:00:28 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**read_and_split_line(int fd)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	if (line == NULL || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	split = ft_split(line, ' ');
	free(line);
	return (split);
}

void	add_points_to_map(char **split, int y, t_fdf *fdf)
{
	int			x;
	t_point		*new_point;
	char		**value_and_color;
	int			z_value;

	x = 0;
	while (split[x])
	{
		new_point = malloc(sizeof(t_point));
		if (new_point == NULL)
		{
			free_line(split);
			write(1, "Error: Memory allocation failed for point\n", 41);
			exit(1);
		}
		new_point->x = (x * fdf->scale) + fdf->offset_x;
		new_point->y = (y * fdf->scale) + fdf->offset_y;
		value_and_color = ft_split(split[x], ',');
		z_value = ft_atoi(value_and_color[0]);
		new_point->z = z_value * fdf->amplitude;
		if (value_and_color[1] != NULL)
		{
			unsigned int	color;
			char			*color_str;
			color = 0;
			color_str = value_and_color[1];
			while (*color_str)
			{
				color = color * 16;
				color += (*color_str >= '0' && *color_str <= '9') ?
							(*color_str - '0') :
							(*color_str >= 'A' && *color_str <= 'F') ?
								(*color_str - 'A' + 10) :
								(*color_str - 'a' + 10);
				color_str++;
			}
			new_point->color = color;
		}
		else
			new_point->color = 0x00FFFFFF;
		free_line(value_and_color);
		ft_lstadd_back(&fdf->map, ft_lstnew(new_point));
		x++;
	}
}

void	get_map(int fd, t_fdf *fdf)
{
	char	**split;
	int		y;
	int		x;
	int		temp_x;

	y = 0;
	x = 0;
	while (1)
	{
		split = read_and_split_line(fd);
		if (split == NULL)
			break ;
		add_points_to_map(split, y, fdf);
		temp_x = 0;
		while (split[temp_x])
			temp_x++;
		if (temp_x > x)
			x = temp_x;
		y++;
		free_line(split);
	}
	fdf->width = x;
	fdf->height = y;
}

void	parse_map(int argc, char **argv, t_fdf *fdf)
{
	int	fd;

	if (argc != 2)
	{
		write(1, "Usage: ./fdf <filename>\n", 24);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	get_map(fd, fdf);
	close(fd);
}
