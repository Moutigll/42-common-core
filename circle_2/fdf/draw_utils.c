/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:24:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/03 09:23:22 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

	printf("adsad");
	line = init_line(a, b);
	printf("adsad%d", line.sx);
	err = line.dx - line.dy;
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, a.x, a.y, a.color);
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
