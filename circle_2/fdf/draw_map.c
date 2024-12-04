/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 05:54:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/04 07:52:41 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*gli(t_list *lst, int index)
{
	while (index--)
		lst = lst->next;
	return (lst);
}

void	draw_line_between_points(t_fdf *fdf, int x, int y)
{
	t_list	*current_point;
	t_point	*point1;
	t_point	*point2;

	current_point = gli(fdf->map, y * fdf->width + x);
	point1 = (t_point *)current_point->content;
	if (x < fdf->width - 1)
	{
		current_point = gli(fdf->map, y * fdf->width + (x + 1));
		point2 = (t_point *)current_point->content;
		draw_line(fdf, *point1, *point2);
	}
	if (y < fdf->height - 1)
	{
		current_point = gli(fdf->map, (y + 1) * fdf->width + x);
		point2 = (t_point *)current_point->content;
		draw_line(fdf, *point1, *point2);
	}
}

void	process_row(t_fdf *fdf, int y)
{
	int	x;

	x = 0;
	while (x < fdf->width)
	{
		draw_line_between_points(fdf, x, y);
		x++;
	}
}

void	draw_map(t_fdf *fdf)
{
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		process_row(fdf, y);
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
