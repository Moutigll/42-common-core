/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:11:04 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/06 16:27:16 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include "minilibx/mlx.h"
#include "libft/include/libft.h"

#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_CTRL 65507
#define KEY_SPC 32
#define KEY_TAB 65289

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	t_list	*map;
	t_list	*original_map;
	int		width;
	int		height;
	int		scale;
	int		screen_height;
	int		screen_width;
	double	rotation_angle_x;
	double	rotation_angle_y;
	double	rotation_angle_z;
	int		offset_x;
	int		offset_y;
	int		amplitude;
	int		axes;
}	t_fdf;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_line;

void	draw_line(t_fdf *fdf, t_point a, t_point b);
void	put_pixel_to_image(t_fdf *fdf, int x, int y, int color);
void	parse_map(int argc, char **argv, t_fdf *fdf);
void	draw_map(t_fdf *fdf);
void	apply_rotation(t_fdf *fdf, double angle_x,
			double angle_y, double angle_z);
t_list	*gli(t_list *lst, int index);
void	rotate_point(t_point *point, double angle_x,
			double angle_y, double angle_z);
void	draw_axes(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
void	clear_image(t_fdf *fdf, int color);