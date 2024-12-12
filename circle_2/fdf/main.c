/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:17:15 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/12 18:36:37 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define MOVE_SPEED 10

void draw_map(t_settings *settings, t_map *map)
{
	int x;
	int y;

	fill_rect(settings->img, 0, 0, WIDTH, HEIGHT, 0x00000000);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(settings, map->points[y][x], map->points[y][x + 1]);
			if (y < map->height - 1)
				draw_line(settings, map->points[y][x], map->points[y + 1][x]);
			x++;
		}
		y++;
	}
}

void scroll(double xdelta, double ydelta, void* param)
{
	t_settings *settings;
	int mouse_x, mouse_y;
	double scale_factor;

	settings = (t_settings *)param;
	(void)xdelta;
	mlx_get_mouse_pos(settings->mlx, &mouse_x, &mouse_y);
	scale_factor = 1;
	if (ydelta > 0 && settings->scale < 100)
	{
		scale_factor = 1.1;
		settings->scale *= scale_factor;
	}
	else if (ydelta < 0 && settings->scale > 1)
	{
		scale_factor = 0.9;
		settings->scale *= scale_factor;
	}

	settings->offset_x += (mouse_x - settings->offset_x) * (1 - scale_factor);
	settings->offset_y += (mouse_y - settings->offset_y) * (1 - scale_factor);

	rotate_map(settings->map, settings->rotation_angle_x, settings->rotation_angle_y, settings);
	draw_map(settings, settings->map);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_settings *settings;
	t_map *map;
	int prev_offset_x;
	int prev_offset_y;

	settings = (t_settings *)param;
	map = settings->map;

	prev_offset_x = settings->offset_x;
	prev_offset_y = settings->offset_y;

	if (keydata.key == MLX_KEY_LEFT_CONTROL)
		settings->control = !settings->control;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT)
		settings->color_mode = !settings->color_mode;
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
		rotate_map(map, settings->rotation_angle_x, settings->rotation_angle_y, settings);
	}
	else
	{
		if (keydata.key == MLX_KEY_UP)
			settings->offset_y += MOVE_SPEED;
		else if (keydata.key == MLX_KEY_DOWN)
			settings->offset_y -= MOVE_SPEED;
		else if (keydata.key == MLX_KEY_LEFT)
			settings->offset_x += MOVE_SPEED;
		else if (keydata.key == MLX_KEY_RIGHT)
			settings->offset_x -= MOVE_SPEED;

		int delta_x = settings->offset_x - prev_offset_x;
		int delta_y = settings->offset_y - prev_offset_y;

		for (int y = 0; y < map->height; y++)
		{
			for (int x = 0; x < map->width; x++)
			{
				map->points[y][x].x += delta_x;
				map->points[y][x].y += delta_y;
			}
		}

	}
	draw_map(settings, map);
}

int main(int argc, char **argv)
{
	t_map *map;
	mlx_t *mlx;
	mlx_image_t *img;
	t_settings *settings;

	if (argc != 2)
		return ((ft_printf("Usage: %s <map>\n", argv[0])), 1);
	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (1);
	settings->scale = 1;
	settings->z_scale = 0.1;
	settings->offset_x = WIDTH / 2;
	settings->offset_y = HEIGHT / 2;
	map = parse_map(argv[1], settings);
	if (!map)
		return (1);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
	{
		ft_printf("Error: MLX42 initialization failed\n");
		free_map(map);
		return (1);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_printf("Error: Failed to create image\n");
		mlx_terminate(mlx);
		free_map(map);
		return (1);
	}

	settings->img = img;
	settings->map = map;
	settings->rotation_angle_x = 0;
	settings->rotation_angle_y = 0;
	settings->control = 0;
	settings->color_mode = 0;
	settings->mlx = mlx;
	rotate_map(map, 0, 0, settings);
	draw_map(settings, map);

	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		ft_printf("Error: Failed to display image\n");
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		free_map(map);
		return (1);
	}

	mlx_key_hook(mlx, key_hook, settings);
	mlx_scroll_hook(mlx, &scroll, settings);

	printf("Number of points: %d\n", map->width * map->height);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	free_map(map);

	return (0);
}
