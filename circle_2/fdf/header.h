/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:08:25 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/12 18:36:03 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "../../libft/include/libft.h"
#include "../../MLX42/include/MLX42/MLX42.h"

#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	t_point	**points;
}	t_map;

typedef struct s_settings
{
	t_map		*map;
	double		scale;
	double		z_scale;
	int			offset_x;
	int			offset_y;
	double		rotation_angle_x;
	double		rotation_angle_y;
	int			control;
	int			color_mode;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_settings;

t_map	*parse_map(char *file, t_settings *settings);
void	free_map(t_map *map);
void	draw_line(t_settings *settings, t_point p0, t_point p1);
int		get_rgba(int r, int g, int b, int a);
void	fill_rect(mlx_image_t *img, int x, int y, int width, int height, unsigned int color);
void rotate_map(t_map *map, double angle_x, double angle_y, t_settings *settings);