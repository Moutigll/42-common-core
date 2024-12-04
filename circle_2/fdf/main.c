/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/04 09:50:45 by ele-lean         ###   ########.fr       */
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
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			put_pixel_to_image(fdf->img_data, x, y, color);
			x++;
		}
		y++;
	}
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	static int	prev_x = -1;
	static int	prev_y = -1;
	int			delta_x;
	int			delta_y;
	double		angle_x;
	double		angle_y;

	if (prev_x != -1 && prev_y != -1)
	{
		delta_x = x - prev_x;
		delta_y = y - prev_y;
		angle_x = delta_x * 0.005;
		angle_y = delta_y * 0.005;
		apply_rotation(fdf->map, angle_x, angle_y, 0);
		clear_image(fdf, 0x000000);
		draw_map(fdf);
	}
	prev_x = x;
	prev_y = y;
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	parse_map(argc, argv, fdf);
	fdf->mlx = mlx_init();
	fdf->scale = 20;
	fdf->win = mlx_new_window(fdf->mlx, 800, 800, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, 800, 800);
	fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	draw_map(fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_hook(fdf->win, 6, 1L << 6, mouse_move, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
