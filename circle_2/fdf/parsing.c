/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:53:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/04 10:17:33 by ele-lean         ###   ########.fr       */
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
	int		x;
	t_point	*new_point;

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
		new_point->x = (x * 20) + 150;
		new_point->y = (y * 20) + 150;
		new_point->z = ft_atoi(split[x]) * 10;
		new_point->color = 0x00FFFFFF;
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