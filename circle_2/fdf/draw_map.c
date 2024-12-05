/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 05:54:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/05 19:27:59 by ele-lean         ###   ########.fr       */
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
	int	x_start;
	int	x_end;

	if ((y * fdf->scale + fdf->offset_y < 0)
		|| (y * fdf->scale + fdf->offset_y >= fdf->screen_height))
		return ;
	if (fdf->offset_x < 0)
		x_start = -fdf->offset_x / fdf->scale;
	else
		x_start = 0;
	x_end = (fdf->screen_width - fdf->offset_x) / fdf->scale;
	if (x_end > fdf->width)
		x_end = fdf->width;
	x = x_start;
	while (x < x_end)
	{
		draw_line_between_points(fdf, x, y);
		x++;
	}
}

void	draw_map(t_fdf *fdf)
{
	int	y;
	int	y_start;
	int	y_end;

	if (fdf->offset_y < 0)
		y_start = -fdf->offset_y / fdf->scale;
	else
		y_start = 0;
	y_end = (fdf->screen_height - fdf->offset_y) / fdf->scale;
	if (y_end > fdf->height)
		y_end = fdf->height;
	y = y_start;
	while (y < y_end)
	{
		process_row(fdf, y);
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
