/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/04 07:50:33 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h> // Pour malloc et free

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img);
	ft_lstclear(&fdf->map, free);
	free(fdf);
	exit(0);
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
	mlx_loop(fdf->mlx);
	return (0);
}
