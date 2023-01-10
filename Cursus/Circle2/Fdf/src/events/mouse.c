/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:36 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 20:14:20 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	on_mousemove(int x, int y, t_vars *vars)
{
	static int	mouse_is_in;
	int			mouse_was_in;

	mouse_was_in = mouse_is_in;
	if (x > 0 && y >= 0 && x <= WIN_W && y <= WIN_H && vars)
		mouse_is_in = 1;
	else
		mouse_is_in = 0;
	if (mouse_was_in && !mouse_is_in)
		printf("Mouse leaving\n");
	else if (!mouse_was_in && mouse_is_in)
		printf("Mouse entering\n");
	return (0);
}

int	on_mousedown(int button, int x, int y, t_vars *vars)
{
	double	scale_diff;

	scale_diff = 0.02;
	if (button == MOUSE_LEFT)
	{
		printf("mouse click at (%d, %d)\n", x, y);
		// img.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
		my_mlx_set_data_addr(vars->img);
		draw_circle(vars, x, y, 100);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	}
	else if (button == MOUSE_SCROLL_UP)
	{
		vars->map->abs_scale += scale_diff;
		vars->map->scale += scale_diff;
		vars->map->z_scale += scale_diff;
		printf("scale : %f\n", vars->map->scale);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		if (vars->map->abs_scale >= 1 + scale_diff)
			vars->map->abs_scale -= scale_diff;
		if (vars->map->scale >= 1 + scale_diff)
			vars->map->scale -= scale_diff;
		// vars->map->scale = 1;
		if (vars->map->z_scale >= 1 + scale_diff)
			vars->map->z_scale -= scale_diff;
		// vars->map->z_scale = 1;
		printf("scale : %f\n", vars->map->scale);
	}
	printf("mouse button: %d\n", button);
	render_next_frame(vars);
	return (0);
}
