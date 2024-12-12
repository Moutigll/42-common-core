/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:06:55 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/12 17:54:57 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}


void	put_pixel_to_image(mlx_image_t *img, int x, int y, unsigned int color)
{
	unsigned char	red;
	unsigned char	blue;

	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
	{
		// Extraire le rouge et le bleu
		red = (color >> 16) & 0xFF;
		blue = color & 0xFF;

		// Inverser le rouge et le bleu
		color = (color & 0xFF00FF00) | (blue << 16) | red;

		// Placer le pixel dans l'image
		((uint32_t *)img->pixels)[y * img->width + x] = color;
	}
}


unsigned int	get_color_from_z(int z, int z_min, int z_max)
{
	float			percentage;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	percentage = (float)(z - z_min) / (z_max - z_min);

	if (percentage <= 0.33)
	{

		red = 255;
		green = 255;
		blue = (unsigned int)(255 * (1 - (percentage / 0.33)));
	}
	else if (percentage <= 0.66)
	{

		red = 255;
		green = (unsigned int)(255 * (1 - ((percentage - 0.33) / 0.33)));
		blue = 0;
	}
	else
	{

		red = (unsigned int)(255 * (1 - ((percentage - 0.66) / 0.34)));

		green = 0;

		blue = (unsigned int)(255 * ((percentage - 0.66) / 0.34) * 0.8);
	}
	return (0xFF << 24) | (red << 16) | (green << 8) | blue;
}




void	draw_line(t_settings *settings, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	percentage;
	int		current_z;

	dx = abs(p1.x - p0.x);
	dy = abs(p1.y - p0.y);

	sx = (p0.x < p1.x) ? 1 : -1;
	sy = (p0.y < p1.y) ? 1 : -1;

	err = dx - dy;

	while (p0.x != p1.x || p0.y != p1.y)
	{
		unsigned int color;


		percentage = 1.0f - (float)(abs(p1.x - p0.x) + abs(p1.y - p0.y)) / (dx + dy);

		if (settings->color_mode == 1)
		{
			current_z = (int)((1 - percentage) * p0.z + percentage * p1.z);
			color = get_color_from_z(current_z, settings->map->z_min, settings->map->z_max);
		}
		else
		{
			unsigned int red = ((1 - percentage) * ((p1.color >> 16) & 0xFF)) +
							   (percentage * ((p0.color >> 16) & 0xFF));
			unsigned int green = ((1 - percentage) * ((p1.color >> 8) & 0xFF)) +
								 (percentage * ((p0.color >> 8) & 0xFF));
			unsigned int blue = ((1 - percentage) * (p1.color & 0xFF)) +
								(percentage * (p0.color & 0xFF));
			color = (0xFF << 24) | (red << 16) | (green << 8) | blue;
		}

		put_pixel_to_image(settings->img, p0.x, p0.y, color);

		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			p0.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			p0.y += sy;
		}
	}
}




void	fill_rect(mlx_image_t *img, int x, int y, int width, int height, unsigned int color)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			put_pixel_to_image(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}