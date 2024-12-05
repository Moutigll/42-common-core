/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:24:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/05 18:47:54 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= fdf->screen_width || y < 0 || y >= fdf->screen_height)
		return ;
	offset = ((int)y * fdf->screen_width + (int)x) * 4;
	*(unsigned int *)((char *)fdf->img_data + offset) = color;
}

t_line	init_line(t_point a, t_point b)
{
	t_line	line;

	line.dx = fabs(b.x - a.x);
	line.dy = fabs(b.y - a.y);
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
	int		ax;
	int		ay;
	int		bx;
	int		by;

	ax = (int)a.x;
	ay = (int)a.y;
	bx = (int)b.x;
	by = (int)b.y;

	line = init_line((t_point){ax, ay, a.z, a.color},
			(t_point){bx, by, b.z, b.color});
	err = line.dx - line.dy;
	while (1)
	{
		put_pixel_to_image(fdf, ax + fdf->offset_x, ay + fdf->offset_y, a.color);
		if (ax == bx && ay == by)
			break ;
		e2 = 2 * err;
		if (e2 > -line.dy)
		{
			err -= line.dy;
			ax += line.sx;
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			ay += line.sy;
		}
	}
}

void	fill_rect(t_fdf *fdf, t_point a, t_point b)
{
	int	x;
	int	y;

	y = (int)a.y;
	while (y < (int)b.y)
	{
		x = (int)a.x;
		while (x < (int)b.x)
		{
			put_pixel_to_image(fdf, x, y, a.color);
			x++;
		}
		y++;
	}
}
