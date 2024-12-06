/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:23:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/06 16:26:27 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	static int	control_pressed = 0;

	printf("keycode: %d\n", keycode);
	if (keycode == KEY_CTRL)
	{
		control_pressed = !control_pressed;
		keycode = 0;
	}
	if (keycode == KEY_TAB)
		fdf->axes = !fdf->axes;
	if (control_pressed)
	{
		if (keycode == KEY_UP)
			fdf->rotation_angle_x += 0.05;
		else if (keycode == KEY_DOWN)
			fdf->rotation_angle_x -= 0.05;
		else if (keycode == KEY_LEFT)
			fdf->rotation_angle_y += 0.05;
		else if (keycode == KEY_RIGHT)
			fdf->rotation_angle_y -= 0.05;
		else if (keycode == KEY_SPC)
			fdf->rotation_angle_z += 0.05;
		printf("rotation x: %f, y: %f, z: %f\n", fdf->rotation_angle_x, fdf->rotation_angle_y, fdf->rotation_angle_z);
		apply_rotation(fdf, fdf->rotation_angle_x, fdf->rotation_angle_y, fdf->rotation_angle_z);
	}
	else
	{
		if (keycode == KEY_UP)
			fdf->offset_y -= fdf->scale;
		else if (keycode == KEY_DOWN)
			fdf->offset_y += fdf->scale;
		else if (keycode == KEY_LEFT)
			fdf->offset_x -= fdf->scale;
		else if (keycode == KEY_RIGHT)
			fdf->offset_x += fdf->scale;
		printf("offset x: %d, y: %d\n", fdf->offset_x, fdf->offset_y);
	}
	clear_image(fdf, 0x00000000);
	draw_map(fdf);
	return (0);
}