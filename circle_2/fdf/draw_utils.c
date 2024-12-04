/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:24:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/04 04:52:00 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(char *img_data, int x, int y, int color)
{
	int	offset;

	offset = (y * 800 + x) * 4;
	*(unsigned int *)(img_data + offset) = color;
}

t_line	init_line(t_point a, t_point b)
{
	t_line	line;

	line.dx = abs(b.x - a.x);
	line.dy = abs(b.y - a.y);
	if (a.x < b.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (a.y < b.y)
		line.sy = 1;
	else
		line.sy = -1;
	return (line);
}

void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	t_line	line;
	int		err;
	int		e2;

	line = init_line(a, b);
	err = line.dx - line.dy;
	while (1)
	{
		put_pixel_to_image(fdf->img_data, a.x, a.y, a.color);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = 2 * err;
		if (e2 > -line.dy)
		{
			err -= line.dy;
			a.x += line.sx;
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			a.y += line.sy;
		}
	}
}

void	fill_rect(t_fdf *fdf, t_point a, t_point b)
{
	int	x;
	int	y;

	y = a.y;
	while (y < b.y)
	{
		x = a.x;
		while (x < b.x)
		{
			put_pixel_to_image(fdf->img_data, x, y, a.color);
			x++;
		}
		y++;
	}
}
