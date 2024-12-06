/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/06 16:30:56 by ele-lean         ###   ########.fr       */
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

void	draw_axes(t_fdf *fdf)
{
	t_point	x_axis;
	t_point	y_axis;
	t_point	z_axis;

	if (fdf->axes)
	{
		x_axis = (t_point){250, 0, 0, 0xFF0000};
		y_axis = (t_point){0, 250, 0, 0x0000FF};
		z_axis = (t_point){0, 0, 250, 0x00FF00};
		rotate_point(&x_axis, fdf->rotation_angle_x,
			fdf->rotation_angle_y, fdf->rotation_angle_z);
		rotate_point(&y_axis, fdf->rotation_angle_x,
			fdf->rotation_angle_y, fdf->rotation_angle_z);
		rotate_point(&z_axis, fdf->rotation_angle_x,
			fdf->rotation_angle_y, fdf->rotation_angle_z);
		draw_line(fdf, (t_point){0, 0, 0, 0xFF0000}, x_axis);
		draw_line(fdf, (t_point){0, 0, 0, 0x0000FF}, y_axis);
		draw_line(fdf, (t_point){0, 0, 0, 0x00FF00}, z_axis);
	}
}

t_list	*copy_list(t_list *original, t_fdf *fdf)
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
		*new_point = *original_point;
		new_point->x = (fdf->scale * original_point->x - (fdf->width * fdf->scale) * 0.5) + fdf->scale / 2;
		new_point->y = (fdf->scale * original_point->y - (fdf->height * fdf->scale) * 0.5) + fdf->scale / 2;
		new_node = ft_lstnew(new_point);
		if (!new_node)
		{
			free(new_point);
			ft_lstclear(&new_list, free);
			write(1, "Error: Memory allocation failed for new node\n", 45);
			exit(1);
		}
		ft_lstadd_back(&new_list, new_node);
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
	fdf->offset_x = 400;
	fdf->offset_y = 400;
	fdf->scale = 20;
	fdf->amplitude = 20;
	fdf->axes = 0;
	parse_map(argc, argv, fdf);
	fdf->original_map = copy_list(fdf->map, fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, fdf->screen_width, fdf->screen_height,
			"fdf");
	fdf->img = mlx_new_image(fdf->mlx, fdf->screen_width, fdf->screen_height);
	fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	apply_rotation(fdf, 0, 0, 0);
	draw_map(fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
