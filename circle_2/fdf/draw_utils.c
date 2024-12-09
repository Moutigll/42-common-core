/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:24:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/07 23:27:51 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_gradient_color(int min, int max, int value)
{
	float			ratio;
	unsigned int	color;
	int				red;
	int				blue;

	if (value <= min)
		return (0x0000FF);
	if (value >= max)
		return (0xFF0000);
	ratio = (float)(value - min) / (max - min);
	red = (int)(255 * ratio);
	blue = 255 - red;
	color = (red << 16) | (0 << 8) | blue;
	return (color);
}

void	put_pixel_to_image(t_fdf *fdf, int x, int y, float z, int color)
{
	int	offset;

	color = get_gradient_color(fdf->z_min, fdf->z_max, z);
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
	float	z; // Variable pour stocker la position z interpolée

	ax = (int)a.x;
	ay = (int)a.y;
	bx = (int)b.x;
	by = (int)b.y;

	// Initialisation de la ligne, en prenant en compte z et la couleur
	line = init_line((t_point){ax, ay, a.z, a.color},
			(t_point){bx, by, b.z, b.color});
	err = line.dx - line.dy;

	// Initialisation de z avec la valeur de a.z (position de départ)
	z = a.z;

	while (1)
	{
		// Interpolation de la valeur z en fonction de l'avancement sur la ligne
		put_pixel_to_image(fdf, ax + fdf->offset_x, ay + fdf->offset_y, z, a.color);

		// Condition de fin si le point atteint le point d'arrivée
		if (ax == bx && ay == by)
			break ;

		e2 = 2 * err;
		
		// Mise à jour de z en fonction de l'avancement sur la ligne
		if (e2 > -line.dy)
		{
			err -= line.dy;
			ax += line.sx;
			// Interpolation linéaire de z pour chaque pixel
			z = a.z + (float)(ax - a.x) / (bx - ax) * (b.z - a.z);
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			ay += line.sy;
			// Interpolation linéaire de z pour chaque pixel
			z = a.z + (float)(ay - a.y) / (by - ay) * (b.z - a.z);
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
			put_pixel_to_image(fdf, x, y, 0, a.color);
			x++;
		}
		y++;
	}
}
