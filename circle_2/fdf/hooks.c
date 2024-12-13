/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:01:54 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 15:52:19 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	scroll(double xdelta, double ydelta, void *param)
{
	t_settings	*settings;
	int			mouse_x;
	int			mouse_y;
	double		scalf;

	settings = (t_settings *)param;
	(void)xdelta;
	mlx_get_mouse_pos(settings->mlx, &mouse_x, &mouse_y);
	scalf = 1;
	if (ydelta > 0 && settings->scale < 100)
		scalf = 1.1;
	else if (ydelta < 0 && settings->scale > 1)
		scalf = 0.9;
	if (settings->scale_mode == 0)
	{
		settings->scale *= scalf;
		settings->offset_x += (mouse_x - settings->offset_x) * (1 - scalf);
		settings->offset_y += (mouse_y - settings->offset_y) * (1 - scalf);
	}
	adjust_points(settings->map, 0, 0, scalf);
	settings->map->z_min *= scalf;
	settings->map->z_max *= scalf;
	rotate_map(settings->map, settings->rotation_angle_x,
		settings->rotation_angle_y, settings);
	draw_map(settings, settings->map);
}

void	handle_key_rotation(mlx_key_data_t keydata, t_settings *settings)
{
	if (keydata.key == MLX_KEY_UP)
		settings->rotation_angle_x += 0.05;
	else if (keydata.key == MLX_KEY_DOWN)
		settings->rotation_angle_x -= 0.05;
	else if (keydata.key == MLX_KEY_LEFT)
		settings->rotation_angle_y += 0.05;
	else if (keydata.key == MLX_KEY_RIGHT)
		settings->rotation_angle_y -= 0.05;
}

void	handle_key_offset(mlx_key_data_t keydata, t_settings *settings)
{
	if (keydata.key == MLX_KEY_UP)
		settings->offset_y -= MOVE_SPEED;
	else if (keydata.key == MLX_KEY_DOWN)
		settings->offset_y += MOVE_SPEED;
	else if (keydata.key == MLX_KEY_LEFT)
		settings->offset_x -= MOVE_SPEED;
	else if (keydata.key == MLX_KEY_RIGHT)
		settings->offset_x += MOVE_SPEED;
}

void	mouse_move_handler(double xpos, double ypos, void *param)
{
	t_settings	*settings;
	int			delta_x;
	int			delta_y;

	settings = (t_settings *)param;
	if (settings->mouse_pressed)
	{
		delta_x = (int)xpos - settings->prev_mouse_x;
		delta_y = (int)ypos - settings->prev_mouse_y;
		if (settings->control)
		{
			settings->rotation_angle_x -= delta_y * 0.01;
			settings->rotation_angle_y += delta_x * 0.01;
		}
		else
		{
			settings->offset_x += delta_x;
			settings->offset_y += delta_y;
		}
		settings->prev_mouse_x = (int)xpos;
		settings->prev_mouse_y = (int)ypos;
		rotate_map(settings->map, settings->rotation_angle_x,
			settings->rotation_angle_y, settings);
		draw_map(settings, settings->map);
	}
}

void	mouse_handler(mouse_key_t button,
	action_t action, modifier_key_t mods, void *param)
{
	t_settings	*settings;
	int			x;
	int			y;

	(void)mods;
	settings = (t_settings *)param;
	mlx_get_mouse_pos(settings->mlx, &x, &y);
	if (button == 0 && action == 1)
	{
		settings->mouse_pressed = 1;
		settings->prev_mouse_x = x;
		settings->prev_mouse_y = y;
	}
	else if (button == 0 && action == 0)
	{
		settings->mouse_pressed = 0;
	}
}
