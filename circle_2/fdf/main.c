/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:17:15 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 15:50:54 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_settings	*settings;
	t_map		*map;

	settings = (t_settings *)param;
	map = settings->map;
	if (settings->control)
		handle_key_rotation(keydata, settings);
	else
		handle_key_offset(keydata, settings);
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
