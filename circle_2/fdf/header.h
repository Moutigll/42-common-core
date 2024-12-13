/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:08:25 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/13 17:18:01 by ele-lean         ###   ########.fr       */
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
#define MOVE_SPEED 10

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

typedef struct s_line_utils
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	percentage;
}	t_line_utils;

typedef struct s_settings
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;

	int			control;
	int			color_mode;
	int			scale_mode;

	double		scale;
	double		z_scale;

	int			offset_x;
	int			offset_y;

	double		rotation_angle_x;
	double		rotation_angle_y;

	int			mouse_pressed;
	int			prev_mouse_x;
	int			prev_mouse_y;
}	t_settings;

//Parse
t_map	*parse_map(char *file, t_settings *settings);
void	free_map(t_map *map);

//Hooks
void	handle_key_offset(mlx_key_data_t keydata, t_settings *settings);
void	handle_key_rotation(mlx_key_data_t keydata, t_settings *settings);
void	mouse_handler(mouse_key_t button,
			action_t action, modifier_key_t mods, void *param);
void	mouse_move_handler(double xpos, double ypos, void *param);
void	scroll(double xdelta, double ydelta, void *param);

//Draw
void	put_pixel_to_image(mlx_image_t *img, int x, int y, unsigned int color);
void	adjust_points(t_map *map, int y, int x, double scale_factor);
void	draw_map(t_settings *settings, t_map *map);
void	draw_line(t_settings *settings, t_point p0, t_point p1);
int		get_rgba(int r, int g, int b, int a);

void	rotate_map(t_map *map,
			double angle_x, double angle_y, t_settings *settings);