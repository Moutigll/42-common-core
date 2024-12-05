/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/05 11:12:42 by ele-lean         ###   ########.fr       */
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

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->offset_y -= 15;
	else if (keycode == KEY_DOWN)
		fdf->offset_y += 15;
	else if (keycode == KEY_LEFT)
		fdf->offset_x -= 15;
	else if (keycode == KEY_RIGHT)
		fdf->offset_x += 15;
	clear_image(fdf, 0x00000000);
	draw_map(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;


	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	fdf->screen_height = 800;
	fdf->screen_width = 800;
	parse_map(argc, argv, fdf);
	fdf->mlx = mlx_init();
	fdf->scale = 20;
	fdf->win = mlx_new_window(fdf->mlx, fdf->screen_width, fdf->screen_height,
			"fdf");
	fdf->img = mlx_new_image(fdf->mlx, fdf->screen_width, fdf->screen_height);
	fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	apply_rotation(fdf->map, 1.5708, 0, 0);
	draw_map(fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
