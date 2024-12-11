/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:06:55 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/11 14:28:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24) | (g << 16) | (b << 8) | a;
}


void	put_pixel_to_image(mlx_image_t *img, int x, int y, unsigned int color)
{
	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
		((uint32_t *)img->pixels)[y * img->width + x] = color;
}

void	draw_line(mlx_image_t *img, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	percentage;

	dx = abs(p1.x - p0.x);
	dy = abs(p1.y - p0.y);

	if (p0.x < p1.x)
		sx = 1;
	else
		sx = -1;

	if (p0.y < p1.y)
		sy = 1;
	else
		sy = -1;

	err = dx - dy;
	percentage = 0.0;

	while (p0.x != p1.x || p0.y != p1.y)
	{
		unsigned int red = ((1 - percentage) * ((p0.color >> 16) & 0xFF)) +
						   (percentage * ((p1.color >> 16) & 0xFF));
		unsigned int green = ((1 - percentage) * ((p0.color >> 8) & 0xFF)) +
							 (percentage * ((p1.color >> 8) & 0xFF));
		unsigned int blue = ((1 - percentage) * (p0.color & 0xFF)) +
							(percentage * (p1.color & 0xFF));
		unsigned int color = (0xFF << 24) | (red << 16) | (green << 8) | blue;

		put_pixel_to_image(img, p0.x, p0.y, color);

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

		percentage = (float)(abs(p0.x - p1.x) + abs(p0.y - p1.y)) / (dx + dy);
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