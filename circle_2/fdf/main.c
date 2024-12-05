/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/05 19:17:37 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img);
	ft_lstclear(&fdf->map, free);
	free(fdf);
	exit(0);
	return (0);
}

void	clear_image(t_fdf *fdf, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->screen_height)
	{
		x = 0;
		while (x < fdf->screen_width)
		{
			put_pixel_to_image(fdf, x, y, color);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_fdf *fdf)
{
	static int	control_pressed = 0;

	if (keycode == KEY_CTRL)
		control_pressed = !control_pressed;
	if (control_pressed)
	{
		if (keycode == KEY_UP)
			fdf->rotation_angle_x += 0.1;
		else if (keycode == KEY_DOWN)
			fdf->rotation_angle_x -= 0.1;
		else if (keycode == KEY_LEFT)
			fdf->rotation_angle_y += 0.1;
		else if (keycode == KEY_RIGHT)
			fdf->rotation_angle_y -= 0.1;
		else if (keycode == KEY_SPC)
			fdf->rotation_angle_z += 0.1;
		printf("x: %f, y: %f, z: %d\n", fdf->rotation_angle_x, fdf->rotation_angle_y, fdf->rotation_angle_z);
		apply_rotation(fdf, fdf->rotation_angle_x, fdf->rotation_angle_y, fdf->rotation_angle_z);
	}
	else
	{
		if (keycode == KEY_UP)
			fdf->offset_y -= fdf->scale;
		else if (keycode == KEY_DOWN)
			fdf->offset_y += fdf->scale;
		else if (keycode == KEY_LEFT)
			fdf->offset_x -= fdf->scale;
		else if (keycode == KEY_RIGHT)
			fdf->offset_x += fdf->scale;
	}
	clear_image(fdf, 0x00000000);
	draw_map(fdf);
	return (0);
}

t_list	*copy_list(t_list *original)
{
	t_list	*new_list;
	t_list	*new_node;
	t_point	*new_point;
	t_point	*original_point;

	new_list = NULL;
	while (original)
	{
		original_point = (t_point *)original->content;
		new_point = malloc(sizeof(t_point));
		if (!new_point)
		{
			ft_lstclear(&new_list, free);
			write(1, "Error: Memory allocation failed while copying list\n", 51);
			exit(1);
		}
		*new_point = *original_point; // Copie les valeurs de `t_point`
		new_node = ft_lstnew(new_point);
		if (!new_node)
		{
			free(new_point);
			ft_lstclear(&new_list, free);
			write(1, "Error: Memory allocation failed for new node\n", 45);
			exit(1);
		}
		ft_lstadd_back(&new_list, new_node); // Ajoute le nœud à la nouvelle liste
		original = original->next;
	}
	return (new_list);
}


int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	fdf->screen_height = 995;
	fdf->screen_width = 1920;
	fdf->offset_x = 0;
	fdf->offset_y = 450;
	fdf->scale = 20;
	fdf->amplitude = 5;
	parse_map(argc, argv, fdf);
	fdf->original_map = copy_list(fdf->map);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->screen_width, fdf->screen_height,
			"fdf");
	fdf->img = mlx_new_image(fdf->mlx, fdf->screen_width, fdf->screen_height);
	fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	apply_rotation(fdf, 1.5708, 0, 0);
	while (fdf->map)
	{
		printf("New one  x: %f, y: %f, z: %f\n", ((t_point *)fdf->map->content)->x,
			((t_point *)fdf->map->content)->y,
			((t_point *)fdf->map->content)->z);
		printf("Original x: %f, y: %f, z: %f\n", ((t_point *)fdf->original_map->content)->x,
			((t_point *)fdf->original_map->content)->y,
			((t_point *)fdf->original_map->content)->z);
		fdf->map = fdf->map->next;
		fdf->original_map = fdf->original_map->next;
	}
	draw_map(fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
