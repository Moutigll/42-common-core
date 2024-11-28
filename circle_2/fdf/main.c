/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/28 13:44:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <mlx.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('x');
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "fdf");
	mlx_key_hook(win, deal_key, (void *)0);
	int x = 50;
	
	while (x < 100)
	{
		int y = 40;
		while (y < 100)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_pixel_put(mlx, win, 100, 100, 0x00FF0000);
	mlx_loop(mlx);
	return (0);
}
