/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:06:55 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 17:17:04 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel_to_image(mlx_image_t *img, int x, int y, unsigned int color)
{
	unsigned char	red;
	unsigned char	blue;

	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
	{
		red = (color >> 16) & 0xFF;
		blue = color & 0xFF;
		color = (color & 0xFF00FF00) | (blue << 16) | red;
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
	return ((0xFF << 24) | (red << 16) | (green << 8) | blue);
}

unsigned int	get_color(t_line_utils utils,
	t_settings *settings, t_point p0, t_point p1)
{
	unsigned int	color;
	int				current_z;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	if (settings->color_mode == 1)
	{
		current_z = (int)(utils.percentage * p0.z
				+ (1 - utils.percentage) * p1.z);
		color = get_color_from_z(current_z,
				settings->map->z_min, settings->map->z_max);
	}
	else
	{
		red = ((1 - utils.percentage) * ((p1.color >> 16) & 0xFF))
			+ (utils.percentage * ((p0.color >> 16) & 0xFF));
		green = ((1 - utils.percentage) * ((p1.color >> 8) & 0xFF))
			+ (utils.percentage * ((p0.color >> 8) & 0xFF));
		blue = ((1 - utils.percentage) * (p1.color & 0xFF))
			+ (utils.percentage * (p0.color & 0xFF));
		color = (0xFF << 24) | (red << 16) | (green << 8) | blue;
	}
	return (color);
}

t_line_utils	init_draw_line(t_point p0, t_point p1)
{
	t_line_utils	utils;

	utils.dx = abs(p1.x - p0.x);
	utils.dy = abs(p1.y - p0.y);
	if (p0.x < p1.x)
		utils.sx = 1;
	else
		utils.sx = -1;
	if (p0.y < p1.y)
		utils.sy = 1;
	else
		utils.sy = -1;
	utils.err = utils.dx - utils.dy;
	return (utils);
}

void	draw_line(t_settings *settings, t_point p0, t_point p1)
{
	t_line_utils	utils;

	utils = init_draw_line(p0, p1);
	while (p0.x != p1.x || p0.y != p1.y)
	{
		utils.percentage = (float)(abs(p1.x - p0.x)
				+ abs(p1.y - p0.y)) / (utils.dx + utils.dy);
		put_pixel_to_image(settings->img,
			p0.x, p0.y, get_color(utils, settings, p0, p1));
		utils.e2 = 2 * utils.err;
		if (utils.e2 > -utils.dy)
		{
			utils.err -= utils.dy;
			p0.x += utils.sx;
		}
		if (utils.e2 < utils.dx)
		{
			utils.err += utils.dx;
			p0.y += utils.sy;
		}
	}
}
