/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:17:15 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/12 21:13:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define MOVE_SPEED 10

static void	draw_lines(t_settings *settings, t_map *map, int x, int y)
{
	if (x < map->width - 1)
		draw_line(settings, map->points[y][x], map->points[y][x + 1]);
	if (y < map->height - 1)
		draw_line(settings, map->points[y][x], map->points[y + 1][x]);
}

void	draw_map(t_settings *settings, t_map *map)
{
	int	x;
	int	y;

	fill_rect(settings->img, 0, 0, WIDTH, HEIGHT, 0x00000000);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_lines(settings, map, x, y);
			x++;
		}
		y++;
	}
}

void	scroll(double xdelta, double ydelta, void* param)
{
	t_settings	*settings;
	int			mouse_x;
	int			mouse_y;
	double		scale_factor;

	settings = (t_settings *)param;
	(void)xdelta;
	mlx_get_mouse_pos(settings->mlx, &mouse_x, &mouse_y);
	scale_factor = 1;
	if (ydelta > 0 && settings->scale < 100)
		scale_factor = 1.1;
	else if (ydelta < 0 && settings->scale > 1)
		scale_factor = 0.9;
	if (settings->scale_mode == 0)
	{
		settings->scale *= scale_factor;
		settings->offset_x += (mouse_x - settings->offset_x) * (1 - scale_factor);
		settings->offset_y += (mouse_y - settings->offset_y) * (1 - scale_factor);
		{
		for (int y = 0; y < settings->map->height; y++)
		{
			for (int x = 0; x < settings->map->width; x++)
			{
				settings->map->points[y][x].z *= scale_factor;
			}
		}
		settings->map->z_min *= scale_factor;
		settings->map->z_max *= scale_factor;
	}
	}
	else
	{
		for (int y = 0; y < settings->map->height; y++)
		{
			for (int x = 0; x < settings->map->width; x++)
			{
				settings->map->points[y][x].z *= scale_factor;
			}
		}
		settings->map->z_min *= scale_factor;
		settings->map->z_max *= scale_factor;
	}
	rotate_map(settings->map, settings->rotation_angle_x,
		settings->rotation_angle_y, settings);
	draw_map(settings, settings->map);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_settings	*settings;
	t_map		*map;

	settings = (t_settings *)param;
	map = settings->map;
	if (settings->control)
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
	else
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
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_LEFT_CONTROL)
		settings->control = !settings->control;
	if (keydata.key == MLX_KEY_LEFT_SHIFT)
		settings->color_mode = !settings->color_mode;
	if (keydata.key == MLX_KEY_TAB)
		settings->scale_mode = !settings->scale_mode;
	rotate_map(map, settings->rotation_angle_x,
		settings->rotation_angle_y, settings);
	draw_map(settings, map);
}

void	mouse_move_handler(double xpos, double ypos, void *param)
{
	t_settings *settings;
	int delta_x;
	int delta_y;

	settings = (t_settings *)param;
	if (settings->mouse_pressed)
	{
		delta_x = (int)xpos - settings->prev_mouse_x;
		delta_y = (int)ypos - settings->prev_mouse_y;
		if (settings->control)
		{
			settings->rotation_angle_x += delta_y * 0.01;
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

void	mouse_handler(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
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

int	main(int argc, char **argv)
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_settings	*settings;

	if (argc != 2)
		return ((ft_printf("Usage: %s <map>\n", argv[0])), 1);
	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (1);
	settings->scale = 10;
	settings->z_scale = 20;
	settings->offset_x = WIDTH / 2;
	settings->offset_y = HEIGHT / 2;
	map = parse_map(argv[1], settings);
	if (!map)
		return (1);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		return (free_map(map), 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (free_map(map), mlx_terminate(mlx), 1);
	settings->img = img;
	settings->map = map;
	settings->rotation_angle_x = 0;
	settings->rotation_angle_y = 0;
	settings->control = 0;
	settings->color_mode = 0;
	settings->mlx = mlx;
	settings->scale_mode = 0;
	rotate_map(map, 0, 0, settings);
	draw_map(settings, map);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (free_map(map), mlx_delete_image(mlx, img),
			mlx_terminate(mlx), 1);
	mlx_mouse_hook(mlx, mouse_handler, settings);
	mlx_cursor_hook(mlx, mouse_move_handler, settings);
	mlx_key_hook(mlx, key_hook, settings);
	mlx_scroll_hook(mlx, &scroll, settings);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	free_map(map);
	return (0);
}
