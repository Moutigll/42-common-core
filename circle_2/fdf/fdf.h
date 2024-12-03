/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:11:04 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/03 05:45:31 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_line;

void	draw_line(t_fdf *fdf, t_point	a, t_point	b);
